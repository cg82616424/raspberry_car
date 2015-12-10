#include "car.h"
car::car():right_back(4,5),right_front(0,1),left_back(2,3),left_front(6,21)
{
    right_back.stop();
    right_front.stop();
    left_front.stop();
    left_back.stop();
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
}
car::~car()
{

}
