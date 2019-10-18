#include <iostream>
#include "Ball_Class.h"
using namespace std;

#ifndef TENNISBALL_CLASS_H
#define TENNISBALL_CLASS_H

class tennisball : public ball{

    private :
            int number;

    public:
            void set_number(int);
            void hit();
            void rest();
            tennisball(int);
            ~tennisball();
};

#endif
