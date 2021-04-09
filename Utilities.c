#include "headers.h"

int ReadButtons(void)
{
    volatile int button;
    button = *PUSH_BUTTON &= 0b1111111111; //and operation with the button bits & 1111
    return button;
}

void TimerCountDown(void)
{
    if (*TIMER == 0b11)
    {
        time++;
        *TIMER = 0;
    }
}

int DelayChecker(void){
        if (*TIMER == 0b11){
            return 1;
        }else{
            return 0;
        }
}

 void IncrementTime(void){
       if(time > 99){
           timeSec++;
           time = 0;
           if(timeSec >=30){
               timeSec = 0;
           }
       }
 }

void StartTimer(void)
{
    InitTimer(1000000);
    //toggles start bit
    *(TIMER_CONTROL) = 4;
}

void disableTimer(int nSeconds)
{
    StartTimer(); //starts the timer
    while (timeSec < 30)
    ;//30 second lock out in the while loop
}

void InitTimer(int interval)
{
    *(TIMER_LVL) = interval;
    *(TIMER_LVH) = interval >> 16;
}

int Exponent(int base, int exponent)
{
    volatile int result = 1;
    while (exponent != 0)
    {
        result *= base;
        exponent--;
    }
    return result;
}