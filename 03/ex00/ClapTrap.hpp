#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cmath>

class ClapTrap
{
	private:
		std::string _name;
		int _hitPoints;
		int _energyPoint;
		int _attackDamage;

	public:
		ClapTrap();
		ClapTrap(std::string name);
		~ClapTrap();
		ClapTrap(const ClapTrap& other);
		ClapTrap& operator = (const ClapTrap& other);

		void attack(const std::string &target);//参照
		void takeDamage(unsigned int amount);//no minus
		void beRepaired(unsigned int amount);//no minus

};

#endif
