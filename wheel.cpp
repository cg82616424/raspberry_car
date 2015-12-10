#include "wheel.h"
#include <iostream>
#include <wiringPi.h>
#include <unistd.h>
using namespace std;
int wheel::direc=FORWARD;
wheel::wheel(int index_1,int index_2)
{
    this->gpio_index_1=index_1;
    this->gpio_index_2=index_2;
    this->gpio_index_1_votage=false;
    this->gpio_index_2_votage=false;
};
/*
 *function:move setwheel move, direction is forward/backward, time is ms
*/
int wheel::move(int direction)
{
    wiringPiSetup();
    pinMode(gpio_index_1,OUTPUT);
    pinMode(gpio_index_2,OUTPUT);
    //set gpio mode as output
    if(direction==FORWARD)
    {
    	digitalWrite(gpio_index_1,HIGH);
    	digitalWrite(gpio_index_2, LOW);
    }
    else
    {
        digitalWrite(gpio_index_1,LOW);
        digitalWrite(gpio_index_2, HIGH);
    }
};
int wheel::stop()
{
    wiringPiSetup();
    pinMode(gpio_index_1,OUTPUT);
    pinMode(gpio_index_2,OUTPUT);
    //set gpio mode as output
    digitalWrite(gpio_index_1,LOW);
    digitalWrite(gpio_index_2, LOW);
    return 0;
};
