# Название микроконтроллера (MCU) и его частота
MCU = atmega328p
F_CPU = 16000000UL

VERTEX_DIR = C:\Projects\vertex-4-polaris\langs\cpp\vertex\std\include

# Имя выходного файла
TARGET = app

# Директории
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
INC_DIR = include

# Инструменты компиляции и флаги
CC = avr-g++
OBJCOPY = avr-objcopy
CFLAGS = -std=c++14 -mmcu=$(MCU) -DF_CPU=$(F_CPU) -I$(INC_DIR) -O3
OBJCOPY_FLAGS = -O ihex

CFLAGS += -I$(VERTEX_DIR)

# Поиск всех исходных файлов в директории src и создание соответствующих
# объектных файлов в директории obj
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(SOURCES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# Правило по умолчанию
all: $(BIN_DIR)/$(TARGET).hex memory

# Отображение использования памяти
memory: $(OBJ_DIR)/$(TARGET).elf
	avr-size --format=avr --mcu=$(MCU) $(OBJ_DIR)/$(TARGET).elf

# Сборка hex файла
$(BIN_DIR)/$(TARGET).hex: $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $(OBJ_DIR)/$(TARGET).elf
	$(OBJCOPY) $(OBJCOPY_FLAGS) $(OBJ_DIR)/$(TARGET).elf $@

# Сборка объектных файлов
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@if not exist "$(OBJ_DIR)" mkdir $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Очистка проекта
clean:
	rm -rf $(OBJ_DIR)/* $(BIN_DIR)/$(TARGET).hex $(OBJ_DIR)/$(TARGET).elf

# Пометка фиктивных целей
.PHONY: all clean
