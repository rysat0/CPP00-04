#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{

    ClapTrap crap1("alex");

    ScavTrap scav1;
    ScavTrap scav2("alexa");
    ScavTrap scav3(scav2);

    scav1 = scav3;

    scav2.attack("target");
	scav2.takeDamage(30);
	scav2.beRepaired(10);
	scav2.guardGate();

	scav2.takeDamage(200);
	scav2.attack("target after death");
	scav2.beRepaired(10);

    return 0;
}
