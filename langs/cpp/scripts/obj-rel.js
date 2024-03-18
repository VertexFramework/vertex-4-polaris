const path = require('path');
const fs = require('fs');

// Изменяем способ получения аргументов: первый аргумент теперь - это название подпапки в 'obj/'
const outputSubDir = process.argv[2]; // Новый аргумент для названия подпапки
const cppFiles = process.argv.slice(3); // Изменяем начальный индекс для cpp файлов
const basePathSequence = path.join('vertex-4-polaris', 'langs', 'cpp', 'vertex');

function createObjectPaths(files) {
    return files.map(file => {
        const basePathIndex = file.indexOf(basePathSequence);
        if (basePathIndex === -1) {
            console.error(`Base path sequence "${basePathSequence}" not found in "${file}". Skipping file.`);
            return null;
        }
        const relativePath = file.slice(basePathIndex + basePathSequence.length + 1);
        const newObjPath = relativePath.replace(/\.cpp$/, '.o'); // Убедитесь, что здесь указано правильное расширение
        // Используем outputSubDir для создания путей
        return path.join('obj', outputSubDir, newObjPath);
    }).filter(Boolean);
}

function createDirectories(files) {
    files.forEach(file => {
        const dirPath = path.dirname(file);
        if (!fs.existsSync(dirPath)) {
            fs.mkdirSync(dirPath, { recursive: true });
        }
    });
}

if (cppFiles.length > 0 && outputSubDir) {
    const objectPaths = createObjectPaths(cppFiles);
    createDirectories(objectPaths);
    objectPaths.forEach(path => console.log(path));
} else {
    console.log('[Vertex 4 Polaris -> scripts]: Usage: node obj.js <output sub-directory> <cpp files...>');
}
