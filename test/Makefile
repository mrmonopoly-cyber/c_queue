C_FLAGS = -Wall -Wextra -fsanitize=address -g
CC = gcc

C_QUEUE_PATH = ..

include $(C_QUEUE_PATH)/Makefile

all: main

main: main.c c_queue.o
	$(CC) $(C_FLAGS) main.c c_queue.o -o main -g

test_clean:
	rm main

clean: test_clean
