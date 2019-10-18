#include <iostream>
#include "Tennisball_Class.h"
using namespace std;

///////////////////////////////////
//      (1)  Method  hit         //
///////////////////////////////////

void tennisball::hit(){
    cout<<"I will hit tennisball number ["<<number<<"]\n";
    ball::hit();                    //Hit method from class ball
    if(durability>0){               //Reduce durability
        durability=durability-5;
    }
}

///////////////////////////////////
//      (2) Method set_number    //
///////////////////////////////////

void tennisball::set_number(int k){  //Set number
    number=k;
}

///////////////////////////////////
//     (3)    Method rest        //
///////////////////////////////////

void tennisball::rest(){
    cout<<"-->Tennis ball number ["<<number<<"] is resting.....\n";
    cout<<"   Due reconstruction of the sleeve ,durability increase by 3....\n   Durability ["<<durability;
    durability = durability +3;
    if(durability>original_dur){
        durability = original_dur;
    }
    cout<<"]..-->..["<<durability<<"]\n"<<endl;
}


///////////////////////////////////
//     (4)    Constructor        //
///////////////////////////////////

tennisball::tennisball(int i){
       cout << "A tennisball      is created, number : "<<i<< endl<<endl;             //Constructor method
       set_number(i);          //Initialize N,library begging empty
}

///////////////////////////////////
//      (5)   Destructor         //
///////////////////////////////////

tennisball::~tennisball(){
       cout<<"A tennisball      is destroyed, number : "<<number<<endl<<endl;   //Destructor method
}


