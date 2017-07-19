#include <iostream>
using namespace std;

/**
 * Inheritance is the process by which a new class, a derived class, is created
 * from another class, the base class.  
 *
 * The derived class inherits all the member variables and ordinary member 
 * functions of the base class.
 *
 * However, derived class CANNOT access private members of base class by name,
 * we must use accessor/mutator funcs present in the base class to manipulate bass class
 * private members.  This can be avoided by using 'protected' instead
 * of 'private', see a different tutorial.
 *
 * Also note that a derived class does not inherit the constructors of its base class. However,
 * when defininng a constructor for the base class, we must call the constructor of the base
 * class within the initialization section of the constructor definition.  
 */

/**
 * Base player class - all players have health and accessor/mutator func
 */
class Player {
    private:
        int health;
    public:
        Player(void) : health(50) { cout << "Player ctor" << endl; };
        void set_health(int h) { health = h; };
        int get_health(void) const { return health; };
};

/**
 * Derived player type 'Orc', inherits all of 'Player' class' members, but also
 * adds some additional members
 *
 * NOTE: ctor for Orc must call ctor for Player, to initialize the inherited player members
 */
class Orc : public Player {
    private:
        int strength;
    public:
        Orc(void) : Player(), strength(75) { cout << "Orc ctor" << endl; };
        void set_strength(int s) { strength = s; }; 
        int get_strength(void) const { return strength; };
};

int main(void) {
    /* Create a player and Orc object */
    Player player;  /* will get a single player-ctor called */
    Orc orc;        /* will first get a player-ctor called, then the orc ctor */

    /* Orc can call own member func and parent member func, since it inherits */
    cout << "Orc Health: " << orc.get_health() << endl;
    cout << "Orc Strength: " << orc.get_strength() << endl;

    /* Player can only call it's own member func, it is the parent class! */
    cout << "Player Health: " << player.get_health() << endl;
    cout << "Player Strength: " << player.get_strength() << endl;

    return 0;
}
