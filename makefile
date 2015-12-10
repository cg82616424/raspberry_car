test:main.o
	mkdir -p  output
	g++ main.cpp -o output/main.o  wheel.h   wheel.cpp -o output/wheel.o  car.h car.cpp -o  output/car.o -o  output/test   -lwiringPi
clean: rm -f output/main.o output/wheel.o output/car.o  output/test
