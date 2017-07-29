#include <iostream>
using namespace std;

/**
 * It is legal to assign a derived class object to a base class object, but doing
 * so will will make any members only defined in the derived ojbect unavailable.
 * This is known as the slicing problem.
 *
 * It can be fixed by using ptrs to objects and virtual functions
 * 
 * Generally:
 *   if pAncestor is a ptr to an ancestor class
 *   if pDescendent is a ptr to a descendent class
 *   then:  pAncestor = pDescendent;
 *   is allowed and none of the members/methods in pDescendent will be lost,
 *   BUT - we will need virtual member funcs to access them
 */

class Pet {
    public:
        string name;
        Pet(string n) { name = n; };
        virtual void print(void) const;
};

class Dog : public Pet {
    public:
        string breed;
        Dog(string b) : Pet("dog") { breed = b; };
        virtual void print(void) const;
};

void Pet::print(void) const {
    cout << "pet name: " << name << endl;
};

void Dog::print(void) const {
    cout << "dog name: " << name << endl;  /* only possible bc name is public in base class */
    cout << "dog breed: " << breed << endl;
};

int main(void) {
    Pet p("bird");
    Dog d("pitbull");

    cout << "Print Pet, which just has a name..." << endl;
    p.print();
    cout << "Print Dog, which has a name and a breed..." << endl;
    d.print();

    cout << "now assign the derived to the base, since a dog IS A pet..." << endl;
    p = d;

    cout << "print Pet, will only print out name and show that we've overwritten bird" << endl;
    p.print();

    /* But - we've sliced off the breed! */
    // cout << "p.breed= " << p.breed << endl; // ILLEGAL - Pet doesn't have a 'breed' member

    cout << "\nNow time to use pointers to show polymorphism..." << endl;
    Pet *pp = new Pet("bird");
    Dog *dp = new Dog("pitbull");

    cout << "Print Pet, which just has a name..." << endl;
    pp->print();
    cout << "Print Dog, which has a name and a breed..." << endl;
    dp->print();

    cout << "Now assign the derived to the base, since a dog IS A pet..." << endl;
    pp = dp;

    cout << "Print Pet, which due to polymorphism - now late-binds to Dog's print!" << endl;
    pp->print();

    return 0;

}

