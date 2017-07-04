#include <iostream>
using namespace std;

/**
 * Constructors can be called explicitly if needed
 */

class Rectangle {
    private:
        int width;
        int height;
    public:
        Rectangle(void);         /* default ctor */
        Rectangle(int x);        /* ctor with one arg */
        int area(void) { return width * height; };
};

#define DEF_VAL 5

Rectangle::Rectangle(void) {
    cout << "In default ctor" << endl;
    width = DEF_VAL; 
    height = DEF_VAL;
};

Rectangle::Rectangle(int x) : width(x), height(DEF_VAL) {
    cout << "In single arg ctor" << endl;
};


int main() 
{
    /* Demonstrate the different initialization forms */
    Rectangle rectA;        
    cout << "rectA.area = " << rectA.area() << endl;

    Rectangle rectB = Rectangle(8);
    cout << "rectB.area = " << rectB.area() << endl;

    return 0;
}
