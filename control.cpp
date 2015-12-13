#include "control.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <sstream>
using namespace std;
control::control()
{
    car_1.stop();
}
control::~control()
{

}
int control::control_with_key_board()
{
    cout<<"\t"<<"up down left right to control the car move,anykey to stop the car"<<endl;
    cout<<"input quit to exit this program"<<endl;
    string input_buffer;
    stringstream ss;

    while (true) {
        cin >> input_buffer;
        cout<<"your input command is"<<input_buffer<<endl;
        if(input_buffer=="quit")
        {
            cout<<"quit command recived, exit 0"<<endl;
	    translate_kbd_to_action(116);
            exit(0);
        }
        int command=int(input_buffer[0]);

        cout<<"do move"<<command<<endl;
        translate_kbd_to_action(command);
    }
    return 0;
}
int control::translate_kbd_to_action(int key)
{
    switch (key) {
    case 97:
        car_1.turn_left();
        break;
    case 119:
        car_1.move_forward();
        break;
    case 100:
        car_1.turn_right();
        break;
    case 115:
        car_1.move_backward();
	break;
    case 116:
	car_1.stop();
	break;
    default:
        car_1.stop();
        break;
    }
    return 0;
}
