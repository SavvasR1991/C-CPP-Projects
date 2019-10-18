#include <iostream>
#include "Ball_Class.h"
using namespace std;

#ifndef PING-PONGBALL_CLASS_H
#define PING-PONGBALL_CLASS_H

class ping_pongball : public ball{

    private :
            int number;
            int randhelper;

    public:
            void rest();
            void set_number(int);
            void hit();
            ping_pongball(int);
            ~ping_pongball();
            bool sudden_plof();
};

#endif
