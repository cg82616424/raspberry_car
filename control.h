#include "car.h"
class control
{
    car car_1;
public:
    control();

    int translate_kbd_to_action(int key);
    int control_with_key_board();
    virtual ~control();
};
