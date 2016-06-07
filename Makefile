all: example

example: example.cpp *.h
	g++ -g -o example --std=c++11 example.cpp



