
#include <iostream>
#include <math.h>
#include <string>


int print(std::string s);             
int print(double dvalue);            
int print(double dvalue, int prec);                                       
using namespace std;
int main(int argc, char *argv[])
{
    const double d = 893094.2987;
    if (argc < 2)
    {
        // These calls to print invoke print( char *s ).
        print("This program requires one argument.");
        print("The argument specifies the number of");
        print("digits precision for the second number");
        print("printed.");
        exit(0);
    }

   
    print(d);

    
    print(d, atoi(argv[1]));
}

// Print a string.
int print(string s)
{
    cout << s << endl;
    return cout.good();
}


int print(double dvalue)
{
    cout << dvalue << endl;
    return cout.good();
}


int print(double dvalue, int prec)
{
    
    static const double rgPow10[] = {
        10E-7, 10E-6, 10E-5, 10E-4, 10E-3, 10E-2, 10E-1,
        10E0, 10E1,  10E2,  10E3,  10E4, 10E5,  10E6 };
    const int iPowZero = 6;

   
    if (prec < -6 || prec > 7)
    {
        return print(dvalue);
    }
   
    dvalue = floor(dvalue / rgPow10[iPowZero - prec]) *
        rgPow10[iPowZero - prec];
    cout << dvalue << endl;
    return cout.good();
}
