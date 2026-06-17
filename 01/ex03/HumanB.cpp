#include "HumanB.hpp"

HumanB::HumanB(std::string name) : weapon(NULL), name(name)
{
}

void HumanB::attack()
{
	if(weapon != NULL)
	{
		std::cout << name << " attacks with their " << weapon->getType()
			<< std::endl << std::flush;
	}
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}

