#include <iostream>
using namespace std;
#include "stonewt.h"

Stonewt::Stonewt(double lbs){
    stone = int(lbs) / Lbs_per_stn;
    pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
    pounds = lbs;
 
}

Stonewt::Stonewt(int stn, double lbs){
    stone = stn;
    pds_left = lbs;
    pounds = stn * Lbs_per_stn + lbs;
}

Stonewt::Stonewt(){
    stone = pounds = pds_left = 0;
}
Stonewt::~Stonewt()
{
}




bool Stonewt::operator<(const Stonewt &st) const
{
    return this->pounds < st.pounds ? true : false; //重载'<'运算符; //调用构造函数进行加法操作并重新设置mode模式;
}

bool Stonewt::operator>(const Stonewt &st) const
{
    return this->pounds > st.pounds ? true : false;
}

bool Stonewt::operator>=(const Stonewt &st) const
{
    return this->pounds >= st.pounds ? true : false;
}

bool Stonewt::operator<=(const Stonewt &st) const
{
    return this->pounds <= st.pounds ? true : false; //重载'<'运算符; //调用构造函数进行加法操作并重新设置mode模式;
}

bool Stonewt::operator==(const Stonewt &st) const
{
    return this->pounds == st.pounds ? true : false; //重载'<'运算符; //调用构造函数进行加法操作并重新设置mode模式;
}
bool Stonewt::operator!=(const Stonewt &st) const
{
    return this->pounds != st.pounds ? true : false; //重载'<'运算符; //调用构造函数进行加法操作并重新设置mode模式;
}



std::ostream &operator<<(std::ostream &os, const Stonewt &st){
    os << st.pounds << " pounds.\n";
    return os;
}