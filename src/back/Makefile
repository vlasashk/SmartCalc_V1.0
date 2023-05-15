CC = gcc
CFLAGS = -std=c11 -Wall -Werror -Wextra
SOURCES = $(wildcard *.c)
OBJECTS = $(patsubst %.c, %.o, $(SOURCES))

all: test
	./test

test: $(OBJECTS)
	$(CC) $(CFLAGS) $(SOURCES) -lm -o test

debug_flag:
	$(eval CFLAGS += -g)

debug: clean debug_flag all
	rm -rf *.o

rebuild: clean all
	
valgrind:
	valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all ./test

clean: 
	rm -rf *.o test