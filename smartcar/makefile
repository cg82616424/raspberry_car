test:main.o
	mkdir -p  output
	g++ main.cpp -o output/main.o  wheel.h   wheel.cpp -o output/wheel.o  car.h car.cpp -o  output/car.o control.h control.cpp -o output/control.o   communication.h communication.cpp -o communication.o -o   output/test   -lwiringPi
clean: rm -f output/*
