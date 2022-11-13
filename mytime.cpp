#include <cmath>
#include "mytime.h"

Time::Time(){
    hours = minites = 0;
}

Time::Time(int h, int m){
    hours = h;
    minites =m;
}
void Time::AddMin(int m){
    minites += m;
    hours += minites / 60;
    minites % 60;
}

void Time::reset(int h, int m){
    hours = h;
    minites =m;
}

Time operator+(const Time &t1, const Time &t2) {
    Time sum;
    sum.minites += (t1.minites + t2.minites);
    sum.hours += (t1.hours + t2.hours + sum.minites / 60);
    sum.minites = sum.minites % 60;
    return sum;
}

Time operator-(const Time &t1, const Time &t2) {
    Time diff;
    int tot1, tot2;
    tot1 = t1.minites + 60 * t1.hours;
    tot2 = t2.minites + 60 * t2.hours;
    diff.minites = (tot2 - tot1) % 60;
    diff.hours = (tot1 - tot2) / 60;
    return diff;
}

Time operator*(double mult, const Time &t) {
    Time result;
    long totalminites = t.hours * mult *60 + t.minites * mult;
    result.hours = totalminites / 60;
    result.minites = totalminites % 60;
    return result;
}

Time operator*(const Time &t, double m){
    return m * t;
}
std::ostream & operator<<(std::ostream &os, const Time &t){
    os << t.hours << " hours, " << t.minites << " minutes";
    return os;
}