#include "emp.h"
#include <iostream>

using namespace std;

abstr_emp::abstr_emp(){
    fname = " ";
    lname = " ";
    job = " ";
}

abstr_emp::abstr_emp(const string & fn, const string & ln, const string &j){
    fname = fn;
    lname = ln;
    job = j;
}

void abstr_emp::ShowAll() const{
    cout << "fname: " << fname << endl;
    cout << "lname: " << lname << endl;
    cout << "job: " << job << endl;
}

void abstr_emp::SetAll(){
    cout << "请输入fname" << endl;
    getline(cin, fname);
    cout << "请输入lname" << endl;
    getline(cin, lname);
    cout << "请输入job" << endl;
    getline(cin, job);
}

ostream & operator<<(ostream &os, const abstr_emp &e){
    os << "fname: " << e.fname << endl;
    os << "lname: " << e.lname << endl;
    os << "job: " << e.job << endl;
    return os;
}

abstr_emp::~abstr_emp(){}

employee::employee():abstr_emp(){}

employee::employee(const string &fn, const string &ln, const string &j):abstr_emp(fn, ln ,j){}

void employee::ShowAll() const{
    abstr_emp::ShowAll();
}

void employee::SetAll(){
    abstr_emp::SetAll();
}

manager::manager():abstr_emp(){
    inchargeof = 0;
}

manager::manager(const string &fn, const string &ln, const string &j, int ico):abstr_emp(fn, ln, j){
    inchargeof = ico;
}

manager::manager(const abstr_emp & e, int ico):abstr_emp(e){//默认的复制构造函数（浅拷贝）
    inchargeof = ico;
}

manager::manager(const manager &m):abstr_emp(m){
    inchargeof = m.inchargeof;
}

void manager::ShowAll() const{
    abstr_emp::ShowAll();
    cout << "In charge of: " << inchargeof << endl;
}

void manager::SetAll(){
    abstr_emp::SetAll();
    cout << "请输入inchargeof: " << endl;
    cin >> inchargeof;
    while (cin.get() != '\n')
        continue;
}

fink::fink():abstr_emp(){
    reportsto = " none ";
}

fink::fink(const string & fn, const string & ln, const string & j, const string & rep):abstr_emp(fn, ln, j){
    reportsto = rep;
}

fink::fink(const abstr_emp & e, const string & rep):abstr_emp(e){
    reportsto = rep;
}

fink::fink(const fink &e):abstr_emp(e){
    reportsto = e.reportsto;
}

void fink::ShowAll() const{
    abstr_emp::ShowAll();
    cout << "Reports to: " << reportsto << endl;
}

void fink::SetAll(){
    abstr_emp::SetAll();
    cout << "Please enter a string for reportsto: ";
    getline(cin, reportsto);
}

highfink::highfink():abstr_emp(), manager(), fink(){}

highfink::highfink(const string & fn, const string & ln, const string &j, const string &rep, int ico):abstr_emp(fn, ln, j), manager(fn, ln, j, ico), fink(fn, ln, j, rep){}

highfink::highfink(const fink &f, int ico) : abstr_emp(f), manager(f, ico), fink(f){}

highfink::highfink(const highfink &h) : abstr_emp(h), manager(h), fink(h){}
highfink::highfink(const abstr_emp &e, const std::string &rpo, int ico) : abstr_emp(e), manager(e, ico), fink(e, rpo)
{
}
highfink::highfink(const manager &m, const std::string &rpo) : abstr_emp(m), manager(m), fink(m, rpo)
{
}

void highfink::ShowAll() const{
    abstr_emp::ShowAll();
    cout << "In charge of: " << manager::InChargeOf() << endl;
    cout << "Reports to: " << fink::ReportsTo() << endl;
    
}

void highfink::SetAll()
{
    abstr_emp::SetAll();//调用基基类而不是基类，时防止基基类被重复调用
    cout << "Please enter a number for inchargerof: ";
    cin >> InChargeOf();
    while (cin.get() != '\n')
        continue;
    cout << "Please enter a string for reportsto: ";
    getline(cin, ReportsTo());
   
}