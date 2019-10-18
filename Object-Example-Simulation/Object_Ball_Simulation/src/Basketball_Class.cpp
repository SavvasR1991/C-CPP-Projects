#include <iostream>
#include "Basketball_Class.h"
using namespace std;

///////////////////////////////////
//     (1)  Method hit           //
///////////////////////////////////

void basketball::hit(){
    cout<<"I will hit basketball number ["<<number<<"]\n";
    ball::hit();            //Hit method from class ball
    if(durability>0){       //Reduce durability
        durability--;
    }
}

///////////////////////////////////
//     (2)   method rest         //
///////////////////////////////////

void basketball::rest(){
    cout<<"-->Basket ball number ["<<number<<"] is resting.....\n";
    cout<<"   There are no improvements at the ball \n   Durability stays the same....["<<durability<<"]\n\n";
}

///////////////////////////////////
//     (3)  Method set_number    //
///////////////////////////////////

void basketball::set_number(int k){      //Method set_number
    number=k;                            //Set the number to the ball
}


///////////////////////////////////
//     (4)    Constructor        //
///////////////////////////////////

basketball::basketball(int i){

       cout << "A basketball      is created, number : "<<i<< endl<<endl;    //Constructor method
                    set_number(i);                                     //Initialize N,library begging empty
}

///////////////////////////////////
//      (5)   Destructor         //
///////////////////////////////////

basketball::~basketball(){
       cout<<"A basketball      is destroyed, number : "<<number<<endl<<endl;   //Destructor method
}
