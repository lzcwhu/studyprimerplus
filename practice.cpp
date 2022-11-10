#include <iostream>
#include "golf.h"

void traverse(Item &item){
    using namespace std;
    cout << "输出:" << item << endl;
}
int main()
{
using namespace std;
   List s;
   Item num;
   while((cin >> num) && (!s.isfull())){
        cin.clear();
        while (cin.get() != '\n')
            continue;
        s.add(num);

   }
    s.visit(traverse);



    return 0;
}
