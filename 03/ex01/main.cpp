#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{

    ClapTrap crap1("alex");

    ScavTrap scav1();
    ScavTrap scav2("alexa");
    ScavTrap scav3(scav2);

    scav1 = scav3;

    scav2.attack(scav4);


    return 0;
}
