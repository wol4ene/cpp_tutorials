#include <iostream>
using namespace std;

/**
 * Classes can be members of other classes. In the constructor,
 * need to use special notation for the invocation of the member variable's
 * constructor within the constructor of the outer class
 * 
 * In example below, Foo contains a member var of class Bar.
 * In Foo's ctor, need to call Bar's ctor in the initialization section
 */

class Bar {
    private:
        int age;
    public:
        Bar(int x) : age(x) { cout << "in one arg ctor for Bar" << endl; };
};

class Foo {
    private:
        int height;
        Bar bar;
    public:
        /* Here in the ctor for Foo, call bar(5) */
        Foo(void) : height(5), bar(5) { cout << "in def ctor for Foo" << endl; };
};

int main() 
{
    /* Demonstrate Foo's ctor which will call Bar's ctor */
    Foo foo;

    return 0;
}

/* Alternatively, this would be Foo's ctor if defined outside of the class */
#ifdef FALSE
Foo::Foo(void) : height(5), bar(5) {
    cout << "In default ctor for Foo" << endl;
};
#endif

