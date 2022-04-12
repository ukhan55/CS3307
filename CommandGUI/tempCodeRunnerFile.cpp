#include <iostream>
using namespace std;

class Enemy{

    protected:
        int attackPower: //every enemy has an attack power
    public:
    void setAttackPower(int a)
    {
      attackPower = a;  

    }


class Ninja: public Enemy //inherits from enemy
{
    public:
    void attack()
    {
        cout << "i am a ninja, ninja chop! - " << attackPower << endl;
    }

    }
}

class Monster: public Enemy //inherits from enemy
{
    public:
    void attack()
    {
        cout << "monster must eat you - " << attackPower << endl; //eats you
    }

    }




};
int main()
{
    Ninja n;
    Monster m;
    Enemy *enemy1 = &n; //made it equal to the address of the ninja object, ninja is of type enemy which is why we can do this, address equal to the pointer
     Enemy *enemy2 = &m;
     enemy1->setAttackPower(20); //bcuz ninja is type of enemy, thats why the line above is valid
    enemy2->setAttackPower(29);
    n.attack;
    m.attack;
}
