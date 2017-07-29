#include <iostream>
using namespace std;

/**
 * Like function templates, classes can be templated as well.
 *
 * Classes will have standard template prefix:  templace<class T>
 * 
 * Member funcs will be defined with template prefix and first part of scope-resolution 
 * operator as className<T>::funcName();
 *
 * To instantiate objects of the class, need to specify which type for T:
 *    className<type> objName;
 */

template<class T>
class Pair {
    private:
        T first;
        T second;
    public:
        Pair(void);
        Pair(T firstVal, T secondVal);
        void setFirst(T newVal);
        void setSecond(T newVal);
        T getFirst(void) const;
        T getSecond(void) const;
};

template<class T>
Pair<T>::Pair(void) : first(0), second(0) {};

template<class T>
Pair<T>::Pair(T firstVal, T secondVal) : first(firstVal), second(secondVal) {};

template<class T>
void Pair<T>::setFirst(T newVal) {
    first = newVal;
};

template<class T>
void Pair<T>::setSecond(T newVal) {
    second = newVal;
}

template<class T>
T Pair<T>::getFirst(void) const {
    return first;
};

template<class T>
T Pair<T>::getSecond(void) const {
    return second;
};

/* Func not associated with the class, but takes a templated-class paramter
 * The caveat here is that the '+' operator must make sense for all values of type T
 */
template<class T>
T addUp(const Pair<T>& thePair) {
    return thePair.getFirst() + thePair.getSecond();
}

int main(void) {
    cout << "Create pair of ints and pair of chars..." << endl;
    Pair<int> intpair(4, 6);
    Pair<char> charpair('f', 'y');
    
    cout << "First int=" << intpair.getFirst() << " second int=" << intpair.getSecond() << endl;
    cout << "First char=" << charpair.getFirst() << " second char=" << charpair.getSecond() << endl;

    cout << "Resetting the intpair to 11,15 and charpair to b,r..." << endl;
    intpair.setFirst(11);
    intpair.setSecond(15);
    charpair.setFirst('b');
    charpair.setSecond('r');

    cout << "First int=" << intpair.getFirst() << " second int=" << intpair.getSecond() << endl;
    cout << "First char=" << charpair.getFirst() << " second char=" << charpair.getSecond() << endl;

    cout << "Now add up the int pair using a non-class function..." << endl;
    cout << "Sum: " << addUp(intpair) << endl;

    return 0;
}
