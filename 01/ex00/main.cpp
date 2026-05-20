#include "Zombie.hpp"

int main()
{
	Zombie *heapZom;

	randomChump("stackZombie");
	heapZom = newZombie("heapZombie");
	heapZom->announce();
	delete heapZom;
	return(0);
}
