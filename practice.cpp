#include <iostream>
using namespace std;
#include "complex0.h"


int main()
{
    Complex a(3.0, 4.0);
    Complex c;
    cout << "Enter a complex num (q to quit)" << endl;
    while (cin >> c){
        cout << "c is " << c << '\n';
        cout << "a is " << a << '\n';
        cout << "a + c is " << a + c << '\n';
        cout << "a - c is " << a - c << '\n';
        cout << "a * c is " << a * c << '\n';
        cout << "2 * c is " << c * 2 << '\n';
        cout << "Enter a complex number (q to quit):\n";
    }
    cout << "Done!\n";
   
    return 0;

}
