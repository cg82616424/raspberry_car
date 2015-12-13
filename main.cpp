#include <wiringPi.h>
#include <unistd.h>
#include "control.h"
int main(int argc, char *argv[])
{
    wiringPiSetup();
    control car_control;
    car_control.control_with_key_board();
    return 0;
}
