#include <iostream>
using namespace std;

/**
 * The copy constructor has one param that is of same type as class
 *
 * Similar to other constructurs, the copy constructor initializes a new object, but does it
 * based on a passed in object.  The goal should be a completely independent new object with a deep copy.
 * 
 * Copy constructor is called in 3 instances:
 * 1) When a class object is being declared and is initialized by another object of the same type
 * 2) When a function returns a value of the clas type (this is frequently skipped by compiler,
        see copy constructor elision
 * 3) Whenever an argument of the class type is plugged-in for a call-by-value parameter
 *
 * If we have a class T that is initalized by a single int, then a regular constructor may be:
 *   T obj1(20);
 * We can then init a new object based on object 'obj1':
 *   T obj2(obj1);  // obj2 initialized by its copy-ctor
 * 
 * The syntax for declaring the copy constructor is:
 *   T(const T& obj);
 */

class Foo {
    private:
        int age;
        int weight;
        int *height;
    public:
        Foo(void);
        Foo(int x, int y, int z);
        Foo(const Foo& obj);
        void print(void) const;
};

Foo::Foo(void) : age(21), weight(155) {
    height = new int;
    *height = 67;
};

Foo::Foo(int x, int y, int z) : age(x), weight(y) {
    height = new int;
    *height = z;
};

/* Copy constructor definition */
Foo::Foo(const Foo& obj) : age(obj.age), weight(obj.weight) {
    cout << "in copy ctor" << endl;

    /* alloc new mem and copy over the value from the passed in object */
    height = new int;
    *height = *obj.height;

    /* Note - the following line is what you'd get by default if you didn't define
     * a copy constructor - the compiler would create a default copy-constructor
     * and would shallow-copy all the members, in which case you'd have two objects
     * now pointing to the same memory.  
     */
    // height = obj.height;
};

void Foo::print(void) const
{
    cout << "Age/Weight/Height/[Height-ptr]: " << 
        age << "/" << weight << "/" << *height << "[" << height << "]" << endl;
}

void dumpFooByValue(const Foo foo)
{
    foo.print();
}

void dumpFooByRef(const Foo& foo)
{
    foo.print();
}

int main() 
{
    /* Create one Foo ojbect */
    Foo foo1(17, 145, 45);

    /* Check that foo1 has 17/145/45 */
    cout << "foo1: ";
    foo1.print();
    cout << endl;

    /* Now init a second object using obj1 */
    cout << "Initing foo2, should get copy ctor..." << endl;
    Foo foo2(foo1);

    /* Check that foo2 has 17/145/45 */
    cout << "foo2: ";
    foo2.print();
    cout << endl;

    /* Call a func that passes in a object by call-by-value, copy-ctor will be called */
    cout << "Calling func that takes an object by value, should get a copy ctor..." << endl;
    cout << "Also note that since the func will have it's own copy, the ptr will be diff that foo2" << endl;
    dumpFooByValue(foo2);
    cout << endl;

    /* Call a func that passes in a object by call-by-ref, copy-ctor will NOT be called */
    cout << "Calling func that takes an object by reference, no copy ctor" << endl;
    cout << "Note that since foo2 is passed by ref, the ptrs should match!" << endl;
    dumpFooByRef(foo2);
    return 0;
}
