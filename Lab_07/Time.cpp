#include "Time.h"

//Contstructors
Time::Time(){
    this->hour = 0;
    this->minute = 0;
    this->second = 0;
}
Time::Time(int h, int m, int s){
    this->hour = h;
    this->minute = m;
    this->second = s;
}

//Getters
int Time::getHour(){
    return hour;
}
int Time::getMinute(){
    return minute;
}
int Time::getSecond(){
    return second;
}

//Setters
void Time::setHour(int h){
    if(h >= 0 && h <= 23){
        this->hour = h;
    }
}
void Time::setMinute(int m){
    if(m >= 0 && m <= 59){
        this->minute = m;
    }
}
void Time::setSecond(int s){
    if(s >= 0 && s <= 59){
        this->second = s;
    }
}