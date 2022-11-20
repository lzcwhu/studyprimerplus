#include <iostream>
#include <cstring>
using namespace std;
#include "cow.h"

Cow :: Cow(){
    strcpy(name , "\0");
    hobby = new char[1]; //对应析构函数释放内存;
    hobby[0] = '\0';
    weight = 0;
}

Cow :: Cow(const char *nm, const char *ho, double wt){
    strcpy(name, nm);
    int len = std::strlen(ho);
    hobby = new char[len+1];
    strcpy(hobby, ho);
    weight = wt;
}

Cow :: Cow(const Cow &c){
    strcpy(name, c.name);
    int len = std::strlen(c.hobby);
    hobby = new char[len+1];
    strcpy(hobby, c.hobby);
    weight = c.weight;
    
}

Cow & Cow ::operator=(const Cow &c){
    if (this == &c)
        return *this;
    delete []hobby;
    int len = std::strlen(c.hobby);
    hobby = new char[len+1];
    std::strcpy(hobby, c.hobby);
    weight = c.weight;
    std::strcpy(name, c.name);
    return *this;
}

Cow :: ~Cow(){
    delete [] hobby;
}

void Cow :: ShowCow() const{
    std::cout << "Cow name: " << name << std::endl;
    std::cout << "Cow hobby: " << hobby << std::endl;
    std::cout << "Cow weight: " << weight << "\n\n";
}