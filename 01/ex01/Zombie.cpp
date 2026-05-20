#include "Zombie.hpp"

Zombie::Zombie()
{
}

Zombie::~Zombie()
{
	std::cout << this->name << " is destroyed\n" << std::flush;
}

void Zombie::announce()
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ...\n" << std::flush;
}

void Zombie::setName(std::string name)
{
	this->name = name;
}
