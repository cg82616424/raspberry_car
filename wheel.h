#include <wiringPi.h>
enum DIRECTION
{
    FORWARD,
    BACKWARD
};
class wheel
{
private:

    double speed; //speed,not used in the first edition
    int gpio_index_1; //output gpio interface 1
    int gpio_index_2; //output gpio interface 2
    bool gpio_index_1_votage; //output gpio interface votage, 1/0,default 0/0
    bool gpio_index_2_votage; //output gpio interface votage, 0,1,default 0/0
public:
    static int direc;
    wheel(int index_1,int index_2);
    wheel();
    int move(int direction); //direction: FORWARD,BACKWARD
    int stop();
};
