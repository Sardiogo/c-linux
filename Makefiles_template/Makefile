# define the executable file
PROJ_NAME = printy
# .c files
C_SOURCE_DIR = ./src
C_SOURCE = $(wildcard $(C_SOURCE_DIR)/*.c)
# .h files
H_SOURCE_DIR = ./includes
H_SOURCE = $(wildcard $(H_SOURCE_DIR)/*.h)
# Object files. $(subst from,to,text)
# replacement on the text text: each occurrence of from is replaced by to.
OBJ_DIR = ./objects
OBJ = $(subst .c,.o,$(subst src,objects,$(C_SOURCE)))
# define library paths in addition to /usr/lib
LFLAGS = -L./lib
LIBS = #-lmylib -lm
# Compiler and linker
CC = gcc
# Flags for compiler
CC_FLAGS =  -W \
        	-Wall \
        	-std=c11 \
        	-pedantic \
			-g
# Command used at clean target
RM = rm -rf

#########################################################
# Compilation and linking
#########################################################
.PHONY: all clean exe objFolder

all: objFolder $(PROJ_NAME)
	@ echo "Main Makefile done"
	@ echo ' '
	@ cd sub-make && $(MAKE) 	#line to compile sub-make

$(PROJ_NAME): $(OBJ)
	@ echo ' '
	@ echo 'Building binary using GCC linker: $@'
	$(CC) $^ -o $@ $(LFLAGS) $(LIBS)
	@ echo ' '
	@ echo 'Finished building binary: $@'
	@ echo ' '

$(OBJ_DIR)/%.o: $(C_SOURCE_DIR)/%.c $(H_SOURCE)
	@ echo ' '
	@ echo 'Building target using GCC compiler: $<'
	$(CC) -c $< $(CC_FLAGS) -I$(H_SOURCE_DIR) -o $@

objFolder:
	@ mkdir -p $(OBJ_DIR)

clean:
	@ $(RM) $(wildcard $(OBJ_DIR)/*.o) $(PROJ_NAME) *~
	@ rmdir $(OBJ_DIR)
	@ cd sub-make && $(MAKE) $@

exe: $(PROJ_NAME)
	./$(PROJ_NAME)
	./sub-make/submake