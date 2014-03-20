CC = g++

all: compile

compile:
	$(CC) src/main.cpp src/network.cpp
