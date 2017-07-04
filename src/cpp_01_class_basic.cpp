#include <iostream>
using namespace std;

/**
 * Simplest class 
 *  Single public variable and member func
 *  'x' can be accessed anywhere through the object
 */
class Simple {
    public:
        int x;
        int get(void) { return x; };
};

int main() 
{
    Simple s;
    s.x = 5;
    cout << "Public access x= " << s.x << endl;
    cout << "Accessor func x= " << s.get() << endl;

    return 0;
}
