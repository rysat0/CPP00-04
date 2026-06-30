#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "Constructor Called" << std::endl;
	this->_attackDamage = 0;
	this->_energyPoints = 10;
	this->_hitPoints = 10;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "Constructor Called" << std::endl;
	this->_name = name;
	this->_attackDamage = 0;
	this->_energyPoints = 10;
	this->_hitPoints = 10;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor Called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << "Copy Constructor Called" << std::endl;
	this->_name = other._name;
	this->_attackDamage = other._attackDamage;
	this->_energyPoints = other._energyPoints;
	this->_hitPoints = other._hitPoints;
}

ClapTrap& ClapTrap::operator = (const ClapTrap& other)
{
	if(this != &other)
	{
		this->_name = other._name;
		this->_attackDamage = other._attackDamage;
		this->_energyPoints = other._energyPoints;
		this->_hitPoints = other._hitPoints;
	}
	return(*this);
}

void ClapTrap::attack(const std::string &target)
{
	if(this->_hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " can't move due to low Hit Points." << std::endl;
		return;
	}
	else if(this->_energyPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " can't move due to low Energy Points." << std::endl;
		return;
	}
	else
	{
		(this->_energyPoints)--;
		std::cout << "ClapTrap " << this->_name << " attacks "
				<< target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	}
	return;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->_name << " is attacked, " << amount << " points decreased" << std::endl;
	if(amount > this->_hitPoints)
	{
		this->_hitPoints = 0;
		std::cout << "ClapTrap " << this->_name << "'s Hit Points is now at 0" << std::endl;
	}
	else
	{
		this->_hitPoints = this->_hitPoints - amount;
		std::cout << "ClapTrap " << this->_name << "'s Hit Points is now at " << this->_hitPoints << std::endl;
	}
}


void ClapTrap::beRepaired(unsigned int amount)
{
	if(this->_hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " can't move due to low Hit Points." << std::endl;
		return;
	}
	else if(this->_energyPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " can't move due to low Energy Points." << std::endl;
		return;
	}
	else
	{
		(this->_energyPoints)--;
		this->_hitPoints = this->_hitPoints + amount;
		std::cout << "ClapTrap " << this->_name << "'s HP heals, now at " << this->_hitPoints << std::endl;
	}
}
