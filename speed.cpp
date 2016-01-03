#include "speed.h"
#include <wiringPi.h>
#include <time.h>
#include <string.h>
#include <iostream>
using namespace std;
int speed::left_gipo_index, speed::right_gpio_index;
int speed::speed_count[60];
speed::~speed()
{

}
speed::speed(int index_l,int index_r)
{
    speed::left_gipo_index=index_l;
    speed::right_gpio_index=index_r;
    pinMode(left_gipo_index, INPUT);
    pinMode(right_gpio_index,INPUT);
    memset(speed::speed_count,0,sizeof(speed::speed_count));

}
void speed::get_speed()
{
    time_t tm_now;
    time(&tm_now);
    if (tm_now%60==0) {
        memset(speed_count,0,sizeof(speed_count));
    }
    speed::speed_count[tm_now%60]+=1;
    return;
}
void speed::update_speed()
{
    while(true)
    {

        wiringPiISR(left_gipo_index, INT_EDGE_FALLING, (&get_speed));

    }
}
