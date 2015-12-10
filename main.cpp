#include <wiringPi.h>
#include <unistd.h>
#include "car.h"
int main(int argc, char *argv[])
{
    car car1;
    car1.turn_right();
    sleep(3);
    car1.turn_left();
    sleep(3);
    car1.move_forward();
    sleep(1);
    car1.move_backward();
    sleep(1);
    car1.stop();
    



    return 0;
}
