C_FLAGS = -Wall -Wextra -fsanitize=address -g
CC = gcc

C_QUEUE_PATH = ..

include $(C_QUEUE_PATH)/Makefile

OBJ_FILE = c_queue.o c_check_input.o

all: main

main: main.c 
	$(CC) $(C_FLAGS) $(OBJ_FILE) main.c -o main -g

test_clean:
	rm main

clean: test_clean
