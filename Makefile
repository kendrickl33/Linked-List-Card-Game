#Makefile

all: game
	./game

game: main.cpp cards.cpp cards.h
	g++ --std=c++11 -Wall main.cpp cards.cpp cards.h -o game

clean: 
	rm game
