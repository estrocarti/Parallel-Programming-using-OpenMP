CC = gcc
CFLAGS = -Wall -O2
LDFLAGS = -lpng -lm

SOURCES = mandel_seq.c pngwriter.c walltime.c
OBJECTS = $(SOURCES:.c=.o)
EXECUTABLE = mandel_seq

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
