CC = gcc
CFLAGS = -Wall -g
SRCS = my_functions.c another_functions.c main.c
OBJS = $(SRCS:.c=.o)
TARGET = my_program

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

%.o: %.c my_functions.h another_functions.h
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean

clean:
	rm -f $(OBJS) $(TARGET)
