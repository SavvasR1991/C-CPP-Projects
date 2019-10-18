#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Ping-Pongball_Class.h"
using namespace std;


///////////////////////////////////
//     (1)    Method hit         //
///////////////////////////////////

void ping_pongball::hit(){

    cout<<"I will hit ping-pongball number ["<<number<<"]\n";
    ball::hit();                        //Hit method from class ball
    if(durability>0&&lost_ball==false&&destroyed_ball==false){ //if the ball is ok
        randhelper = randhelper+7+durability;
        destroyed_ball = sudden_plof();                 //check if it will pop
        if(destroyed_ball==true){
            cout<<"!!!!...Whoa!!The ball is destroyed...!!!!\n\n";
        }
        else{                                //Reduce durability
            durability--;
        }
    }
}

///////////////////////////////////
//     (2)   Method rest         //
///////////////////////////////////

void ping_pongball::rest(){
    cout<<"-->Ping-Pong ball number ["<<number<<"] is resting.....\n";
    cout<<"   Due freezing of the ball ,durability increase by 1....\n   Durability ["<<durability;
    durability = durability +1;
    if(durability>original_dur)
        durability = original_dur;
    cout<<"]..-->..["<<durability<<"]\n"<<endl;
}

///////////////////////////////////
//     (3)  Method sudden_plof   //
///////////////////////////////////

bool ping_pongball::sudden_plof(){

    int current_time;
    int result;
    current_time=time(NULL);
    srand((unsigned int)current_time+randhelper);   //Initialize srand
    result = rand()%100;
    if(result<40){              //if possibility is less than 40% pop
        return true;
    }
    else{                       //if possibility is more than 40% don't pop
        return false;
    }
}

///////////////////////////////////
//     (4)  Method set_number    //
///////////////////////////////////

void ping_pongball::set_number(int k){          //set ball number
    number=k;
}


///////////////////////////////////
//     (5)    Constructor        //
///////////////////////////////////

ping_pongball::ping_pongball(int i){
       cout << "A ping_pongball   is created, number : "<<i<< endl<<endl;             //Constructor method
       set_number(i);                                             //Initialize N,library begging empty
}

///////////////////////////////////
//      (6)   Destructor         //
///////////////////////////////////

ping_pongball::~ping_pongball(){
       cout<<"A ping_pongball   is destroyed, number : "<<number<<endl<<endl;   //Destructor method
}
