#ifndef STONEWT_H_
#define STONEWT_H_
#include <iostream>
class Stonewt{
    private:
        enum{ Lbs_per_stn = 14 };
        int stone;
        double pds_left;
        double pounds;
    public:
        Stonewt(double lbs);
        Stonewt(int stn, double lbs);
        Stonewt();
        ~Stonewt();
        bool operator<(const Stonewt &st) const;  //重载'<'运算符;
        bool operator>(const Stonewt &st) const;  //重载'>'运算符;
        bool operator<=(const Stonewt &st) const; //重载'<='运算符;
        bool operator>=(const Stonewt &st) const; //重载'>='运算符;
        bool operator==(const Stonewt &st) const; //重载'=='运算符;
        bool operator!=(const Stonewt &st) const; //重载'!='运算符;
        friend std::ostream &operator<<(std::ostream &os, const Stonewt &st);                //重载'*'运算符;

  
};

#endif
