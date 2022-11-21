#include <iostream>
#include <cstring>
using namespace std;
#include "stock20.h"

Stock::Stock(){
    company = new char[1];
    company[0] = '\0';
    shares = 0;
    share_val = 0.0;
    total_val = 0.0;
}

Stock::Stock(const std::string &co, long n, double pr){
    int len = co.length();
    company = new char[len + 1];
    strcpy(company, co.c_str());
    if (n < 0){
        std::cout << "Number of shares can't be negative;" << company << " shares set to 0.\n";
        shares = 0;
    }
    else
        shares = n;
    share_val = pr;
    set_tot();
}

Stock::~Stock(){
    delete [] company;
}

void Stock::buy(long num, double price){
    if (num < 0){
        std::cout << "Number of shares purchased can't be negative. Transaction is aborted.\n";
    }
    else{
        shares += num;
        share_val = price;
        set_tot();
    }
}

void Stock::sell(long num, double price){
    using std::cout;
     if (num < 0){
        std::cout << "Number of shares purchased can't be negative. Transaction is aborted.\n";
    }
    else if (num > shares){
        cout << "You can't sell more than you have!";
    }
    else{
        shares -= num;
        share_val = price;
        set_tot();
    }

}

void Stock::update(double price){
    share_val = price;
    set_tot();
}
ostream & operator<<(ostream &os, const Stock &s){
    using std::ios_base;
    ios_base::fmtflags orig = os.setf(ios_base::fixed, ios_base::floatfield);
    std::streamsize prec = os.precision(3);
    os << "Commpany:" << s.company << "Shares:" << s.shares << "\n";
    os << " Share Price: $" << s.share_val;
    os.precision(2);
    os << " Total Worth:$" << s.total_val << "\n";
    os.setf(orig, ios_base::floatfield);
    os.precision(prec);
    return os;
}

const Stock & Stock::topval(const Stock &s) const{
    if (s.total_val > total_val)
        return s;
    else
        return *this;
}