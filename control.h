#include "car.h"
class control
{
    car car_1;
public:
    control();
    double cur_speed(int utc);
    int translate_kbd_to_action(int key);
    int control_with_key_board();
    virtual ~control();
};
