#include <wiringPi.h>
#include <unistd.h>
#include "communication.h"
int main(int argc, char *argv[])
{
    wiringPiSetup();
    //control car_control;
    //car_control.control_with_key_board();
    communication test;
    test.start_listen();

    return 0;
}
