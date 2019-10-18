                // Source file "main.cpp"//
//Contains the main method
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Ball_Class.h"
#include "Game_class.h"
#include "Basketball_Class.h"
#include "Tennisball_Class.h"
#include "Ping-Pongball_Class.h"
using namespace std;

int main(int argc, char *argv[]){
    if ( argc != 6 ) {             // argc should be 2 for correct execution
        cout<<"\n!!!Wrong input from commant list, must insert 5 arguments !!!"<< endl;
        return 0;
    }
    int l1,l2,l3,n,k;           //Durabilities,n and k from command list
    int current_time;           //Current time for random
    int bask=0,tenn=0,ping=0;   //Number of ball from each type for creation
    int i,j;          //Counters
    int result;                 //Random result
    bool lostball;              //Check if ball is lost
    bool destroyedball;         //Check if ball is destroyed
    bool wornoutball;
    int goodbask=0,goodtenn=0,goodping=0;  //The good balls
    game gameball;

    l1=atoi(argv[1]);            //Argument from command list
    l2=atoi(argv[2]);            //Argument from command list
    l3=atoi(argv[3]);            //Argument from command list
    n= atoi(argv[4]);             //Argument from command list
    k= atoi(argv[5]);             //Argument from command list

    if(l1<=l2||l2<=l3||l1<=l3){
        cout <<"Wrong durabilities at command list !!!!!!\n\nBasketball > Tennisball > Ping-pongball !!!!!!\n\n";
        return 0;
    }

    ball *ballarray[n];
    current_time=time(NULL);           //Set current time
    srand((unsigned int)current_time); //Initialize srand

    for(i=0;i<n;i++){           //Select how many balls from each type
        result = rand()%100;    //Possibility 0-100%
        if(result<33){          //If poss.<33% select basket
            ballarray[i]  = new basketball(bask);
            ballarray[i]->set_durability(l1);
            bask++;}
        else if(result>66){     //If poss.>66% select tennis
             ballarray[i] = new tennisball(tenn);
             ballarray[i]->set_durability(l2);
             tenn++;}
        else{                   //Else select ping_pong
            ballarray[i]  = new ping_pongball(ping);
            ballarray[i]->set_durability(l3);
            ping++;}
    }

    if(bask==0&&tenn==0&&ping==0){ //If all results from random are zero
        cout<<"\nNo balls to play....end of program\n\n";
        return 0;                  //Finish the program
    }
    else{
        cout<<"\n* Balls created : -> Basketball    =   "<<bask<<"\n"; //Print total balls
        cout<<"                  -> Tennisball    =   "<<tenn<<"\n";
        cout<<"                  -> Ping-pongball =   "<<ping<<"\n\n\n";
    }

    for(i=0;i<n;i++){
        result = rand()%n;
        ballarray[result]->hit();
        for(j=0;j<n;j++){
            lostball = ballarray[j]->read_lost_ball();
            destroyedball = ballarray[j]-> read_destroyed_ball();
            if(j!=result&&lostball==false&&destroyedball==false)
                ballarray[j]->rest();
        }
    }

    //gameball.game_to_play();            //Select the game to play

    cout<<"\n\n";
    for(i=0;i<n;i++){
        delete ballarray[i];
    }

    return 0;                       //End program
}
