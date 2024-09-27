/* c program for a digital clock*/
#include<stdio.h>
#include<time.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
    int hour ,minute,second;
    hour=minute=second=0;
    while(1)
    {
        //clear output screen
        system("clear");
        //print time in hh:mm:ss format
        printf("%02d : %02d : %02d",hour,minute,second);
        //clear output buffer in gcc

    fflush(stdout);
     //increment seconds
    second ++ ;
    if( second == 60)
    {
        minute+=1;
        second =0;
    }
    //increment minutes
    if(minute == 60)
    {
        hour +=1;
        minute =0; 
        second =0;
    }
    //increment hours
    if (hour == 24)
    {
        hour =0;
        minute =0;
        second =0;
    }
    sleep(1); //wait for 1 second 
    }
    return 0;
}
