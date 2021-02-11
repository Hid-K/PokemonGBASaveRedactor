CC = g++

CFLAGS = -Wall -Wextra -time -lstdc++fs

all:
	$(CC) $(CFLAGS) main.cpp -o build/PSR