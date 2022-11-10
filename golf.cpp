#include <iostream>
#include <cstring>
#include "golf.h"

bool List :: isfull() const{
    return index == max;
}
bool List :: isempty() const{
    return index == 0;
}
List :: List(){
    index = 0;
}
void List :: add(const Item &item){
    items[index++] = item;
}
void List :: visit(void (*pf)(Item &)){
    for (int i = 0; i < index; i++)
        (*pf)(items[i]);
}
