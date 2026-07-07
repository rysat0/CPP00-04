#include "FragTrap.hpp"


FragTrap::FragTrap() : ClapTrap()
{
	this->_name = "default";
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap " << this->_name <<" constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->_name <<" destructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout << "FragTrap Copy Constructor Called" << std::endl;
}

FragTrap& FragTrap::operator = (const FragTrap& other)
{
	std::cout << "FragTrap Copy Assignment Operator Called" << std::endl;
	if(this != &other)
		ClapTrap::operator=(other);
	return(*this);
}

void FragTrap::attack(const std::string& target)
{
	if(this->_hitPoints == 0 || this->_energyPoints == 0)
	{
		std::cout << "FragTrap " << this->_name << " can't move" << std::endl;
		return ;
	}
	(this->_energyPoints)--;
	std::cout << "FragTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage
		<< " points of damage" << std::endl;
}


void FragTrap::highFivesGuys(void)
{
	std::cout << "Hey Guys Can I get high-fives??" << std::endl;
}
