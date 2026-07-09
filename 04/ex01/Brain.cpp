#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain Default Constructor Called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain Destructor Called" << std::endl;
}

Brain::Brain(const Brain& other)
{
	std::cout << "Brain Copy Constructor Called" << std::endl;
	*this = other;
}

Brain& Brain::operator = (const Brain& other)
{
	int i = 0;
	if (this != &other)
	{
		while(i < 100)
		{
			this->ideas[i] = other.ideas[i];
			i++;
		}
	}
	return (*this);
}
