# Configuration
MCU = atmega328p
F_CPU = 16000000UL
VERTEX_PATH = C:/Projects/vertex-4-polaris/langs/cpp/vertex/std/include
TARGET = app

# Директории
SRC_PATH = src
OBJ_PATH = obj
BIN_PATH = bin
INC_PATH = include

# Инструменты компиляции и флаги
CC = avr-g++
OBJCOPY = avr-objcopy
OBJDUMP = avr-objdump # Добавлено
CFLAGS = -std=c++14 -mmcu=$(MCU) -DF_CPU=$(F_CPU) -I$(INC_PATH) -I$(VERTEX_PATH)\
-flto -O3 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -mrelax -g2 -Wall
LDFLAGS = -flto -Wl,--start-group -Wl,-lm  -Wl,--end-group -Wl,--gc-sections -mrelax -Wl,-Map=$(BIN_PATH)/$(TARGET).map
OBJCOPY_FLAGS = -O ihex
OBJDUMP_FLAGS = -h -S # Добавлено

# Поиск всех исходных файлов в директории src и создание соответствующих
# объектных файлов в директории obj
SOURCES = $(wildcard $(SRC_PATH)/*.cpp)
OBJECTS = $(SOURCES:$(SRC_PATH)/%.cpp=$(OBJ_PATH)/%.o)

# Правило по умолчанию
all: $(BIN_PATH)/$(TARGET).hex $(BIN_PATH)/$(TARGET).lss memory

# Дизасемблер
$(BIN_PATH)/$(TARGET).lss: $(OBJ_PATH)/$(TARGET).elf # Добавлено
	$(OBJDUMP) $(OBJDUMP_FLAGS) $< > $@

# Отображение использования памяти
memory: $(OBJ_PATH)/$(TARGET).elf
	avr-size --format=avr --mcu=$(MCU) $(OBJ_PATH)/$(TARGET).elf

# Сборка hex файла
$(BIN_PATH)/$(TARGET).hex: $(OBJ_PATH)/$(TARGET).elf
	$(OBJCOPY) $(OBJCOPY_FLAGS) $< $@

# Сборка исполняемого файла
$(OBJ_PATH)/$(TARGET).elf: $(OBJECTS)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@

# Сборка объектных файлов
$(OBJ_PATH)/%.o: $(SRC_PATH)/%.cpp
	@if not exist "$(OBJ_PATH)" mkdir $(OBJ_PATH)
	$(CC) $(CFLAGS) -c $< -o $@

# Очистка проекта
clean:
	rm -rf $(OBJ_PATH)/* $(BIN_PATH)/$(TARGET).hex $(BIN_PATH)/$(TARGET).map $(OBJ_PATH)/$(TARGET).elf $(BIN_PATH)/$(TARGET).lss

# Пометка фиктивных целей
.PHONY: all clean memory
