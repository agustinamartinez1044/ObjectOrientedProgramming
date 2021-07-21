# ----------------------------------------------------------
# Makefile para el laboratorio 5 de Programacion 4
# ----------------------------------------------------------

.PHONY: principal clean

all: clean obj_folders principal

# Main-folders
H_DIR   = include
CPP_DIR = src
O_DIR   = obj

# Sub-folders
CLASES_DIR        = clases
CONTROLADORES_DIR = controladores
DATATYPES_DIR     = datatypes

CC = g++

# Compiling options
CC_FLAGS = -Wall -Werror -I$(H_DIR) -g

# Modules
CLASES_MODULES        = $(shell find $(H_DIR)/$(CLASES_DIR) -type f -name "*.h")
CLASES_MODULES        := $(CLASES_MODULES:include/%.h=%)

CONTROLADORES_MODULES = $(shell find $(H_DIR)/$(CONTROLADORES_DIR) -type f -name "*.h")
CONTROLADORES_MODULES := $(CONTROLADORES_MODULES:include/%.h=%)

DATATYPES_MODULES     = $(shell find $(H_DIR)/$(DATATYPES_DIR) -type f -name "*.h")
DATATYPES_MODULES     := $(DATATYPES_MODULES:include/%.h=%)

principal: $(O_DIR)/principal.o $(CLASES_MODULES:%=$(O_DIR)/%.o) $(CONTROLADORES_MODULES:%=$(O_DIR)/%.o) $(DATATYPES_MODULES:%=$(O_DIR)/%.o)
	$(CC) $(CC_FLAGS) $^ -o $@

$(O_DIR)/principal.o: principal.cpp
	$(CC) $(CC_FLAGS) -c $< -o $@

$(O_DIR)/%.o: $(CPP_DIR)/%.cpp $(H_DIR)/%.h
	$(CC) $(CCFLAGS) -c $< -o $@

obj_folders:
	@mkdir -p $(O_DIR)/$(CLASES_DIR) $(O_DIR)/$(CONTROLADORES_DIR) $(O_DIR)/$(DATATYPES_DIR)

clean:
	@rm -f principal
	@rm -f -r $(O_DIR)/
