const path = require('path');
const fs = require('fs');

// Получаем аргументы командной строки (исключая 'node' и имя скрипта)
const cppFiles = process.argv.slice(2);

// Функция для создания путей к .o файлам
function createObjectPaths(files) {
    return files.map(file => {
        // Заменяем расширение файла на .o
        const newObjPath = file.replace(/\.cpp$/, '.o');
        // Формируем новый путь, добавляя 'obj/' к пути
        return path.join('obj', newObjPath);
    });
}

// Функция для создания директорий
function createDirectories(files) {
    files.forEach(file => {
        // Получаем путь к директории файла
        const dirPath = path.dirname(file);
        // Создаем директорию, если она еще не существует
        if (!fs.existsSync(dirPath)) {
            fs.mkdirSync(dirPath, { recursive: true });
        }
    });
}

const objectPaths = createObjectPaths(cppFiles);

if (cppFiles.length > 0) {
    createDirectories(objectPaths);
    objectPaths.forEach(path => console.log(path));
} else {
	console.log('[Vertex 4 Polaris -> scripts]: Usage: node obj.js <directories>');
}
