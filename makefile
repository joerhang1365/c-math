CC=gcc
CFLAGS=-std=c17 -I./include
LDFLAGS=-lm

SOURCE_FILES=$(wildcard src/*.c)
OBJECTS=$(SOURCE_FILES:.c=.o)

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

program: $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@

clean:
	rm -f $(OBJECTS) program
