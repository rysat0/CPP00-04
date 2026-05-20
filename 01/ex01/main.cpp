#include "Zombie.hpp"

int main()
{
	int n;
	int i;
	Zombie *horde;

	n = 10;
	i = 0;
	horde = zombieHorde(n, "zomzom");
	while(i < n)
	{
		std::cout << "Zombie No." << (i + 1) << ": " << std::flush;
		horde[i].announce();
		i++;
	}
	std::cout << std::endl;
	delete[] horde;
	return 0;
}
