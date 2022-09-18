TARGET := main

CC := clang

CFLAGS :=

CSRCS := $(shell find src -type f -name '*.c')
COBJ := $(CSRCS:.c=.o)

.PHONY: all run clean
all: $(TARGET)

run: all
	./$(TARGET)


$(TARGET): $(COBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(COBJ) $(TARGET)
