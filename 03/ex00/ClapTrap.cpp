#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
}

ClapTrap::ClapTrap(std::string name)
{
	this->_name = name;
}

ClapTrap::~ClapTrap()
{
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	this->_name = other._name;
	this->_attackDamage = other._attackDamage;
	this->_energyPoint = other._energyPoint;
	this->_hitPoints = other._hitPoints;
}

ClapTrap& ClapTrap::operator = (const ClapTrap& other)
{
	if(this != &other)
	{
		this->_name = other._name;
		this->_attackDamage = other._attackDamage;
		this->_energyPoint = other._energyPoint;
		this->_hitPoints = other._hitPoints;
	}
	return(*this);
}

void ClapTrap::attack(const std::string &target)
{
	
}
