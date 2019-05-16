# define the executable file
PROJ_NAME = main_menu
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

##########################
# Compilation and linking
##########################
.PHONY: all clean exe objFolder control_structures functions_pointers_op pointers-arrays_op tic-tac-toe

all: objFolder $(PROJ_NAME)
	@ echo "Main Makefile done"
	@ echo ' '

$(PROJ_NAME): $(OBJ)
	@ echo ' '
	@ echo 'Building binary using GCC linker: $@'
	$(CC) $^ -o $@
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

exe: $(PROJ_NAME)
	./$(PROJ_NAME)

control_structures: ./src/control_structures.c
	$(CC) $(CC_FLAGS) -o $@ $<
	./$@
	rm $@

functions_pointers_op: ./src/functions_pointers_op.c
	$(CC) $(CC_FLAGS) -o $@ $<
	./$@
	rm $@

pointers-arrays_op: ./src/pointers-arrays_op.c
	$(CC) $(CC_FLAGS) -o $@ $<
	./$@
	rm $@

tic-tac-toe: ./src/tic-tac-toe.c
	$(CC) $(CC_FLAGS) -o $@ $<
	./$@
	rm $@