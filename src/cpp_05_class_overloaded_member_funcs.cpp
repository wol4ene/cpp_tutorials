#include <iostream>
using namespace std;

/**
 * Illustrate overloaded member functions in a class
 *
 * Overloaded functions have the same name, but different numbers or types
 * of arguments
 */
class Average {
    public:
        double avg(double n1, double n2);
        double avg(double n1, double n2, double n3);
};

/* Define function outside class using scope-resolution operator */
double Average::avg(double n1, double n2) {
    return (n1 + n2) / 2;
}
double Average::avg(double n1, double n2, double n3) {
    return (n1 + n2 + n3) / 3;
}

int main() 
{
    Average a;

    cout << "Avarge of 10,20 = " << a.avg(10,20) << endl;
    cout << "Avarge of 5,8,13 = " << a.avg(5,8,13) << endl;

    return 0;
}
