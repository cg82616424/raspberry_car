#include "car.h"
class control
{
    int translate_kbd_to_action(int key);
    car car_1;
public:
    control();
    int control_with_key_board();
    virtual ~control();
};
