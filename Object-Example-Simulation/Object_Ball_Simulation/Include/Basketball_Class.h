#include <iostream>
#include "Ball_Class.h"
using namespace std;

#ifndef BASKETBALL_CLASS_H
#define BASKETBALL_CLASS_H

class basketball : public ball {

    private :
            int number;
    public:
            void rest();
            void set_number(int);
            basketball(int);
            ~basketball();
            void hit();
};

#endif
