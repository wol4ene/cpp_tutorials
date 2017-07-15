#include <iostream>
using namespace std;

/**
 * Whenever a class has dynamic memory, need the following:
 *  1) Copy Constructor                
 *  2) Overloaded Assignment Operator  
 *  3) Destructor                     
 *
 *  Copy Constructor
 *     Declaration Syntax:  T(const T& obj);
 *     Definition  Syntax:  T::T(const T& obj);

 *  Destructor  
 *     Declaration Syntax:  ~T();
 *     Definition  Syntax:  T::~T();
 *
 *  Overloaded Assignment Operator
 *     Declaration Syntax:  T& operator=(const T& rhs);
 *     Definition  Syntax:  T& T::operator=(const T& rhs);
 */

class Foo {
    private:
        int numElem; /* size of array */
        int *arr;    /* array of ints */
    public:
        Foo(void);                      /* default ctor */
        Foo(int size);                  /* single-arg ctor */
        
        /* The big three! */
        Foo(const Foo& obj);            /* copy-constructor */
        ~Foo(void);                     /* destructor */
        Foo& operator=(const Foo& rhs); /* overloaded assignment operator */

        void setPos(int pos, int val);  /* set a value at a given position */
        void printAll(void);            /* print the entire array */
};

Foo::Foo(void) : numElem(5) {
    cout << "In default ctor..." << endl;
    arr = new int[numElem];
    for (int i = 0; i < numElem; i++) {
        arr[i] = 0;
    }
};

Foo::Foo(int size) : numElem(size) {
    cout << "In default ctor..." << endl;
    arr = new int[numElem];
    for (int i = 0; i < numElem; i++) {
        arr[i] = 0;
    }
}

Foo::Foo(const Foo& obj) : numElem(obj.numElem) {
    cout << "In copy ctor..." << endl;
    arr = new int[numElem];
    for (int i = 0; i < numElem; i++) {
        arr[i] = obj.arr[i];
    }
}

Foo::~Foo(void) {
    cout << "In dtor..." << endl;
    delete [] arr;
}

Foo& Foo::operator=(const Foo& rhs) {
    cout << "In overloaded assignment operator..." << endl;
    if (this == &rhs) {
        cout << "detected identical lhs and rhs" << endl;
        return *this;
    }
    cout << "in overloaded operator=, rhs.size: " << rhs.numElem << ", calling.size: " << numElem << endl;
    /* free calling object's memory */
    delete [] arr;

    /* re-create calling objects internals based on rhs passed in */
    numElem = rhs.numElem;
    arr = new int[numElem];
    for (int i = 0; i < numElem; i++) {
        arr[i] = rhs.arr[i];
    }

    /* finally, return this object */
    return *this;
}

void Foo::setPos(int pos, int val) {
    arr[pos] = val;
};

void Foo::printAll(void) {
    for (int i = 0; i < numElem; i++) {
        cout << "i[" << i << "]= " << arr[i] << endl;
    }
}

int main(void) {
    cout << "Create Foo object, default ctor, and print it..." << endl;
    Foo f1;
    f1.printAll();

    cout << "Set some values in Foo object, and print it " << endl;
    for (int i = 0; i < 5; i++) {
        f1.setPos(i, i + 7);
    }
    f1.printAll();

    cout << "Create second object using copy-constructor for first obj" << endl;
    cout << "Dumping it should yield identical values" << endl;
    Foo f2(f1);   /* NOTE: Alternatively could have done Foo f2 = f1 */
    f2.printAll();

    cout << "Create third object with default ctor, values will be all zero..." << endl;
    Foo f3;
    f3.printAll();

    cout << "Now assing f2 to f3, invoking assignment operator..." << endl;
    f3 = f2;
    f3.printAll();

    cout << "Create a small Foo object and add a couple values to it..." << endl;
    Foo f4(3);
    f4.setPos(0, 15);
    f4.setPos(1, 54);
    f4.setPos(2, 88);
    f4.printAll();
    
    cout << "Now reassign f2 to f4, should clean up f4 first" << endl;
    f4 = f3;
    f4.printAll();

    return 0;
}
        
