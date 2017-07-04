#include <iostream>
using namespace std;

/**
 * Constructors have mulitple ways they can be called
 *
 *  Functional form: enclosing args to constructors in parentheses
 *  Assignment form: if only a single arg, can assign a value
 *  Uniform    form: instead of parentheses, can use braces
 *    NOTE: 'uniform' requires C++11, so must compile with "-std=c++11"
 */

class Rectangle {
    private:
        int width;
        int height;
    public:
        Rectangle(void);         /* default ctor */
        Rectangle(int x);        /* ctor with one arg */
        Rectangle(int x, int y); /* ctor with two args */
        int area(void) { return width * height; };
};

#define DEF_VAL 5;

Rectangle::Rectangle(void) {
    cout << "In default ctor" << endl;
    width = DEF_VAL; 
    height = DEF_VAL;
};

Rectangle::Rectangle(int x) {
    cout << "In single arg ctor" << endl;
    width = x;
    height = DEF_VAL;
};

Rectangle::Rectangle(int x, int y) {
    cout << "In two arg ctor" << endl;
    width = x;
    height = y;
};

int main() 
{
    /* Demonstrate the different initialization forms */
    Rectangle rectA(7);      /* functional form */
    Rectangle rectB = 8;     /* assignment form (can only use one arg ctor) */
    Rectangle rectC{9};      /* uniform form */
    Rectangle rectD {10,11}; /* another uniform */

    cout << "rectA.area = " << rectA.area() << endl;
    cout << "rectB.area = " << rectB.area() << endl;
    cout << "rectC.area = " << rectC.area() << endl;
    cout << "rectD.area = " << rectD.area() << endl;

    return 0;
}
