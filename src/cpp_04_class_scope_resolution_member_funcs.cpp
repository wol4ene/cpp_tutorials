#include <iostream>
using namespace std;

/**
 * Illustrate scope resolution operator for defining member functions
 *
 * Member functions can be defined inline in the class, or 
 * outside the class using the scope resolution operator
 *    <return> <ClassName>::<FuncName>(<args>) { };
 */
class Rectangle {
    private:
        int width;
        int height;
    public:
        /* Two APIs defined inline in the class */
        int getWidth(void) { return width; };
        void setWidth(int w) { width = w; };

        /* Two APIs declared in the class, but defined outside */
        int getHeight(void);
        void setHeight(int h);
};

/* Define function outside class using scope-resolution operator */
int Rectangle::getHeight(void) {
    return height;
};

void Rectangle::setHeight(int h) {
    height = h;
};

int main() 
{
    Rectangle rect;

    rect.setWidth(5);
    rect.setHeight(7);
    cout << "Rect width = " << rect.getWidth() << endl;
    cout << "Rect height = " << rect.getHeight() << endl;

    return 0;
}
