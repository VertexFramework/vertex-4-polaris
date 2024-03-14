# Project template in C++ language
TARGET = blink


# Vertex 4 Polaris path
VERTEX_PATH = /home/robotsvision/projects/vertex-4-polaris
PLATFORM_PATH = /home/robotsvision/projects/vertex-4-polaris

# Vertex 4 configuration
VERTEX_INC_PATH = $(VERTEX_PATH)/langs/cpp/vertex/std/include
POLARIS_INC_PATH = $(VERTEX_PATH)/langs/cpp/polaris/include
VERTEX_SCRIPTS 	= $(VERTEX_PATH)/langs/cpp/scripts

# Project configuration
PROJECT_SRC_PATH = src
PROJECT_INC_PATH = include
PROJECT_OBJ_PATH = obj
PROJECT_DEP_PATH = obj/.d

PROJECT_SOURCES = $(shell node $(VERTEX_SCRIPTS)/find.js src .cpp)
PROJECT_OBJECTS = $(shell node $(VERTEX_SCRIPTS)/obj.js $(PROJECT_SOURCES))

VERTEX_SOURCES = $(shell node $(VERTEX_SCRIPTS)/find.js $(VERTEX_INC_PATH) .hpp)
VERTEX_OBJECTS = $(shell node $(VERTEX_SCRIPTS)/obj-rel.js polaris/ $(VERTEX_SOURCES))

POLARIS_SOURCES = $(shell node $(VERTEX_SCRIPTS)/find.js $(VERTEX_INC_PATH) .cpp)
POLARIS_OBJECTS = $(shell node $(VERTEX_SCRIPTS)/obj-rel.js $(VERTEX_SOURCES))

all: print

print:
	@echo $(VERTEX_OBJECTS)