#include "wheel.h"
class car
{
    wheel right_back;
    wheel right_front;
    wheel left_back;
    wheel left_front;

public:
    car();
    int move_forward();
    int move_backward();
    int stop();
    int turn_left();
    int turn_right();
    virtual ~car();
};
