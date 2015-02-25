# My makefile for Programm Homework4.cpp
# the compiler to use.
CC = g++
CFLAGS = -Wall

all: hw4

hw4: philip.cpp

	${CC} ${CFLAGS} philip.cpp -o philip

clean:
	rm  -rf philip
