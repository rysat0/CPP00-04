#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	this->_name = "default";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap " << this->_name <<" constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->_name <<" destructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << "ScavTrap Copy Constructor Called" << std::endl;
}

ScavTrap& ScavTrap::operator = (const ScavTrap& other)
{
	std::cout << "ScavTrap Copy Assignment Operator Called" << std::endl;
	if(this != &other)
		ClapTrap::operator=(other);
	return(*this);
}

void ScavTrap::attack(const std::string& target)
{
	if(this->_hitPoints == 0 || this->_energyPoints == 0)
	{
		std::cout << "ScavTrap " << this->_name << " can't move" << std::endl;
		return ;
	}
	(this->_energyPoints)--;
	std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage
		<< " points of damage" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->_name << " is now in Gate Keeper mode"
		<< std::endl;
}
