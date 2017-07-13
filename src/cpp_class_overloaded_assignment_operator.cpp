#include <iostream>
using namespace std;

/**
 * The assignment operator is special and used when a class has dynamic memory
 *
 * By default, the compiler will create a default assignment operator, but this will
 * not perform a deep-copy.
 *
 * The assignment operator must be defined as an overloaded member function
 *
 * Additionally, to allow chained assignments such as a=b=c; the return value must
 * be a reference to the calling object on the left-hand-side.
 *
 * Additionally, to avoid issues with dynamic memory when something like this is done: a=a,
 * the operator much check for 'this' != &rhs.
 *
 * Syntax:
 *   T& operator=(const T& rhs);
 */

class Foo {
    private:
        int age;
        int weight;
        int *height;
    public:
        Foo(void);
        Foo(int x, int y, int z);
        void print(void);
        Foo& operator=(const Foo& rhs);
};

Foo::Foo(void) : age(21), weight(155) {
    height = new int;
    *height = 67;
};

Foo::Foo(int x, int y, int z) : age(x), weight(y) {
    height = new int;
    *height = z;
};

void Foo::print(void) 
{
    cout << "Age/Weight/Height: " << age << "/" << weight << "/" << *height << endl;
}

Foo& Foo::operator=(const Foo& rhs)
{
    /* check for both sides being equal */
    if (this == &rhs) {
        cout << "Detected identical objects on each side, returning this" << endl;
        return *this;
    }
    /* copy over the non-dynamic members */
    age = rhs.age;
    weight = rhs.weight;

    /* delete the calling object's dynamic var and recreate
     * note that since this is just an int*, it's not really necessary to delete and new
     * but... if the dynamic memory in question were instead an array of ints, or structs,
     * then likely the calling ojbect's array would be of different size, so delete it
     * and create a new one 
     */
    delete height;
    height = new int;
    *height = *rhs.height;

    /* finally, return this object */
    return *this;
}

int main() 
{
    /* Create two Foo objects */
    Foo foo1(17, 145, 45), foo2;

    /* Before assignment, foo1 will have 17/145/45 and foo2 will default to 21/155/67 */
    cout << "Before assignment:" << endl;
    foo1.print();
    foo2.print();

    /* Here, foo2 is the calling object and foo1 is the argument to the operator= */
    foo2 = foo1;

    /* After assignment, foo2 should be identical to foo1 */
    cout << "After assignment:" << endl;
    foo1.print();
    foo2.print();

    /* Test the check for identical objects on each side */
    cout << "Checking for identical objects:" << endl;
    foo1 = foo1;
    return 0;
}
