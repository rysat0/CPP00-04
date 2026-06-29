#include "ClapTrap.hpp"

int main(void)
{

    ClapTrap test1("alex");
    ClapTrap test2("bob");

    test1.attack("bob");
    test1.attack("air");
    test1.attack("ground");
    int i = 0;
    while(i < 7)
    {
        test1.attack("fight!");
        i++;
    }

    test1.attack("air");
    test1.beRepaired(10);

    test2.takeDamage(150);
    test2.attack("air");
    test2.beRepaired(10);

    ClapTrap test3(test1);
    ClapTrap test4;

    test4 = test3;
    return 0;
}
