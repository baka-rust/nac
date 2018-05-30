CC = gcc
CFLAGS = -c -Iinclude
LDFLAGS = -lSDL2
SOURCES = $(wildcard src/*.c)
OBJECTS = $(SOURCES:.c=.o)
EXECUTABLE = nac

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f src/*.o core.* $(EXECUTABLE)
