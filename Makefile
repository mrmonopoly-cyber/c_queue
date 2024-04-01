C_FLAGS = -Wall -Wextra -fsanitize=address -g
CC = gcc

c_queue_src_path := $(or $(C_QUEUE_ROOT), .)

c_queue.c = $(c_queue_src_path)/c_queue.c

all: c_queue.o

c_queue.o: $(c_queue.c)
	$(CC) $(C_FLAGS) $(c_queue.c) -c

c_queue_clean:
	rm c_queue.o

clean: c_queue_clean
