#include <iostream>
using namespace std;

/**
 * The 'this' pointer is a predefined pointer that points to the calling
 * object for a class.  
 * 
 * Normally used in an overloaded assignment operator
 * 
 * Cannot be used in the definition of a static member func, since static member
 * funcs do not have a calling object.
 */

class Foo {
    private:
        int x;
    public:
        Foo(void) : x(5) {};
        void print(void) const;
};

void Foo::print(void) const
{
    cout << "x printed with direct access = " << x << endl;
    cout << "x printed with 'this' pointer = " << this->x << endl;
}

int main() 
{
    Foo f;
    f.print();

    return 0;
}
