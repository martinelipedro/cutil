SOURCES = $(shell find . -type f -name '*.c')
HEADERS = $(shell find . -type f -name '*.h')
OBJECTS = $(SOURCES:.c=.o)

.PHONY: all

all: $(OBJECTS) $(HEADERS)
	gcc $^ -o $@

%.o: %.c
	gcc -c $< -o $@