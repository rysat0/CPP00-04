#include "Zombie.hpp"

Zombie *newZombie( std::string name )
{
	Zombie *zom;

	zom = new Zombie;
	zom->setName(name);
	return zom;
}

Zombie* zombieHorde( int N, std::string name )
{
	int i;
	Zombie *horde;

	i = 0;
	horde = new Zombie[N];
	while(i < N)
	{
		horde[i].setName(name);
		i++;
	}
	return horde;
}
