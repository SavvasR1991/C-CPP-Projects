#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

#ifndef BALL_CLASS_H
#define BALL_CLASS_H

class ball{

    private   :
                int randhelper;
                int result;


    protected :
                int durability;
                int original_dur;
                bool lost_ball;
                bool wornout_ball;
                bool check_if_lostball;
                bool destroyed_ball;

    public    :

        ///////////////////////////////////
        //     (1)    Constructor        //
        ///////////////////////////////////
                ball(){
                    lost_ball = false;
                    check_if_lostball = false;
                    destroyed_ball = false;
                    wornout_ball = false;
                    randhelper = 0;
                };
        ///////////////////////////////////
        //     (2)    Destructor         //
        ///////////////////////////////////
                ~ball(){};

        ///////////////////////////////////
        //  (3)   Method set_durability  //
        ///////////////////////////////////
                 virtual void set_durability(int dur){
                     durability = dur;
                     original_dur = dur;
                 };
        ///////////////////////////////////
        //     (4)    Method hit         //
        ///////////////////////////////////
                 virtual void hit(){
                    randhelper = randhelper+7+durability;
                    check_if_lost();
                    if(check_if_lostball==false&&destroyed_ball==false){
                        if(durability>0){
                            cout<<"..Tsaf!!.......\n";
                            wornout_ball = false;
                        }
                        else{
                            cout<<"..Plof!!.......\nThe ball is worn out\n";
                            durability = 0;
                            wornout_ball = true;
                        }
                        lost_or_not();
                        if(lost_ball==true){
                            cout<<"Oupss!!!The ball gone lost,now is hidden...!\n\n";
                        }
                    }
                    else if(destroyed_ball==false&&check_if_lostball==true){
                        cout<<"!!!!..You cannot hit a hidden ball..!!!!\n\n";
                    }
                    if(destroyed_ball==true&&check_if_lostball==false){
                        cout<<"!!!!..You cannot hit a destroyed ball..!!!!\n\n";
                    }
                };

        ///////////////////////////////////
        //    (5)    Method rest         //
        ///////////////////////////////////
                virtual void rest(){};

        ///////////////////////////////////
        //   (6)   Method lost_or_not    //
        ///////////////////////////////////
                void lost_or_not(){
                     int current_time;
                     current_time=time(NULL);
                     srand((unsigned int)current_time+randhelper);   //Initialize srand
                     result =rand()%100;
                     if(result<30){
                        lost_ball = true;
                     }
                     else{
                        lost_ball = false;
                     }
                    // cout<<result<<" = result in fuction  "<<randhelper<<" = randhelper   "<<lost_ball<<" = lostball\n\n";
                };
        ///////////////////////////////////
        //  (7)  Method check_if_lost    //
        ///////////////////////////////////
                void check_if_lost(){
                    if(lost_ball==true){
                        check_if_lostball = true;
                    }
                    else{
                        check_if_lostball = false;
                    }

                }
        ///////////////////////////////////
        // (8)  Method read_lost_ball    //
        ///////////////////////////////////
                virtual bool read_lost_ball(){
                    return lost_ball;
                }
        ///////////////////////////////////
        // (9) Method read_destroyed_bal //
        ///////////////////////////////////
                virtual bool read_destroyed_ball(){
                    return destroyed_ball;
                }
        ///////////////////////////////////
        //(10) Method read_wornout_ball  //
        ///////////////////////////////////
                virtual bool read_wornout_ball(){
                    return wornout_ball;
                }

};
#endif
