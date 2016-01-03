#include "wheel.h"
#include "speed.h"
#include <wiringPi.h>
#include <thread>
using namespace std;
class car
{
    wheel right_back;
    wheel right_front;
    wheel left_back;
    wheel left_front;
    speed car_speed;
    thread *t;
public:
    car();
    int move_forward();
    int move_backward();
    int stop();
    int turn_left();
    int turn_right();
    int update_speed();
    double get_speed(int utc);

    virtual ~car();
};
