#include <iostream>
using std::cout;
#include "stonewt.h"


int main()
{
    using std::cout;
    using std::endl;
    using std::cin;
    Stonewt sw[6] = {Stonewt(285.7), Stonewt(21, 8), Stonewt(12.0)};
    Stonewt temp(11.0);
    Stonewt min, max;
    double val;
    int count;
    for (int i = 3; i < 6; i++){
        while(!(cin >> val)){
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout << "Illegal input! Enter an number: ";
        }
        sw[i] = Stonewt(val);
    }
    min = max = sw[0];
    for (int i = 0; i < 6; i++)
    {
        if (sw[i] < min)
        {
            min = sw[i];
        }
        if (max < sw[i])
        {
            max = sw[i];
        }
        if (temp <= sw[i])
        {
            ++count;
        }
    }
    cout << "The minimum pounds are: " << min;
    cout << "The maximum pounds are: " << max;
    cout << "There are " << count << " elements more than 11 pounds." << endl;

   
    return 0;

}
