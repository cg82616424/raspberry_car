#include "car.h"
car::car():right_back(4,5),right_front(0,1),left_back(2,3),left_front(6,23),car_speed(7,21)
{
    right_back.stop();
    right_front.stop();
    left_front.stop();
    left_back.stop();
    update_speed();

}
int car::move_forward()
{
    right_back.move(FORWARD);
    right_front.move(FORWARD);
    left_back.move(FORWARD);
    left_front.move(FORWARD);
    return 0;
};
int car::move_backward()
{
    right_back.move(BACKWARD);
    right_front.move(BACKWARD);
    left_back.move(BACKWARD);
    left_front.move(BACKWARD);
    return 0;
};
int car::turn_left()
{
    right_back.move(FORWARD);
    right_front.move(FORWARD);
    left_back.move(BACKWARD);
    left_front.move(BACKWARD);
    return 0;

}
int car::turn_right()
{
    right_back.move(BACKWARD);
    right_front.move(BACKWARD);
    left_back.move(FORWARD);
    left_front.move(FORWARD);
    return 0;
}
int car::stop()
{
    right_back.stop();
    right_front.stop();
    left_front.stop();
    left_back.stop();
    return 0;
}
int car::update_speed()
{
    t=new thread(speed::update_speed);
    t->detach();
    return 0;
}
double car::get_speed(int utc)
{
    utc-=1;

    return speed::speed_count[utc%60];
}
car::~car()
{

    t->join();
    delete t;
}
