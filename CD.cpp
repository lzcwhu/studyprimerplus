#include "CD.h"
#include <iostream>
#include <cstring>


Cd::Cd(const char *s1, const char *s2, int n, double x){
    int len1 = strlen(s1);
    performers = new char[len1 + 1];
    strcpy(performers, s1);
    int len2 = strlen(s2);
    label = new char[len2 + 1];
    strcpy(label, s2);
    selections = n;
    playtime = x;
}

Cd::Cd(const Cd &d){
    strcpy(performers, d.performers);
    strcpy(label, d.label);
    selections = d.selections;
    playtime = d.playtime;
}

Cd::Cd(){
    performers = new char[1];
    label  = new char[1];
    strcpy(performers , "\0");
    strcpy(label, "\0");
    selections = 0;
    playtime = 0.0;
}

Cd::~Cd(){
    delete []performers;
    delete []label;
}

void Cd::Report() const{
    using std::cout;
    cout << "performers: " << performers << "label: " << label << "selections: " << selections << "playtime: " << playtime;
}

Cd & Cd::operator=(const Cd &d){
    if (this == &d)
        return *this;
    delete []performers;
    delete []label;
    int len1 = strlen(d.performers);
    performers = new char[len1 + 1];
    strcpy(performers, d.performers);
    int len2 = strlen(d.label);
    label = new char[len2 + 1];
    strcpy(label, d.label);
    selections = d.selections;
    playtime = d.playtime;
    return *this;
}

Classic::Classic(){
    Cd();
    name = new char[1];
    strcpy(name, "\0");
}

Classic::Classic(const char *s1, const char * s2, const char *s3, int n, double x):Cd(s1, s2, n, x){
    int len = strlen(s3);
    name = new char[len + 1];
    strcpy(name, s3);
}

Classic::~Classic(){
    delete []name;
}

void Classic::Report() const{
    using std::cout;
    Cd::Report();
    cout << "name: " << name;
}

Classic & Classic::operator=(const Classic &d){
    if (this == &d)
        return *this;
    Cd::operator=(d);
    int len = strlen(d.name);
    name = new char[len + 1];
    strcpy(name, d.name);
    return *this;

}

Classic::Classic(const char *s, const Cd &d) : Cd(d)
{   
    int len = strlen(s);
    name = new char[len + 1];
    std::strcpy(name, s);

}