all: dzizer.o

dzizer.o: dzizer.cpp
	g++ -std=c++17 -Wall -o dzizer.o -g dzizer.cpp `pkg-config vips-cpp --cflags --libs`