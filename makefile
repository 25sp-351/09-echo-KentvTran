CC = gcc
CFLAGS = -Wall -Wextra -I. -pthread  
LDFLAGS = -pthread          
LDFLAGS = 
TARGET = echo_server

SRCS = main.c socket_utils.c connection_handler.c
OBJS = $(SRCS:.c=.o)

FORMAT = clang-format
FORMAT_FLAGS = -i --style=file
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

format:
	$(FORMAT) $(FORMAT_FLAGS) $(SRCS) *.h
	
clean:
	rm -f $(TARGET) *.o
