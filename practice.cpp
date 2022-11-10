#include <iostream>
#include <cstdlib>
#include <ctime>
#include "vect.h"


int main()
{
    using namespace std;
    using VECTOR :: Vector;
    srand(time(0));
    double direction;
    Vector step;
    Vector result(0.0, 0.0);
    unsigned long steps = 0;
    double target;
    double dstep;
    cout <<  "Enter target distance (q to quit):";
    while (cin >> target){
        cout << "Enter step len:";
        if (!(cin >> dstep))
            break;
        while (result.magval() < target){
            direction = rand() % 360;
            step.reset(dstep, direction, Vector::POL);
            result = result + step;
            steps++;
        }
        cout << "steps = " << steps << endl;\
        cout << "subject has the following location :" << result << endl;
        steps = 0;
        result.reset(0.0, 0.0);
        cout <<  "Enter target distance (q to quit):";
    }
    cout << "Bey!";


    return 0;
}
