#include <iostream>
using namespace std;

/**
 * Illustrate diff b/n pulbic and private members.
 *
 * Public members can be accessed through the object at any time
 * Private members can only be accessed by member functions within the object 
 */

class Simple {
    private:
        int y;
        int getY(void) { return y; };
    public:
        int x;
        int getX(void) { return x; };
};

int main() 
{
    Simple s;
    s.x = 5;      // No problem - x is public
    //s.y = 6;    // COMPILE ERROR, y is private

    cout << "x = " << s.x << endl;       // No problem, x is public
    cout << "x = " << s.getX() << endl;  // No problem, x is public

    //cout << "y = " << s.getY() << endl;  // COMPILE ERROR, 'getY' is private

    return 0;
}
