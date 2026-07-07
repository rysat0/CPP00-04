#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{

    ClapTrap crap1("alex");

    FragTrap frag1;
    FragTrap frag2("alexa");
    FragTrap frag3(frag2);

    frag1 = frag3;

    frag2.attack("target");
	frag2.takeDamage(30);
	frag2.beRepaired(10);
	frag2.highFivesGuys();

	frag2.takeDamage(200);
	frag2.attack("target after death");
	frag2.beRepaired(10);

    return 0;
}
