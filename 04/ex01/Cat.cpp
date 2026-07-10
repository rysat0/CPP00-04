#include "Cat.hpp"

void Cat::makeSound() const
{
	std::cout << "Myaw Myaow" << std::endl;
}

Cat::Cat()
{
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << "Cat Default Constructor Called" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat Destructor Called" << std::endl;
	delete this->brain;
}

Cat::Cat(std::string type)
{
	this->brain = new Brain();
	this->type = type;
	std::cout << "Cat Assignment Constructor Called" << std::endl;
}

Cat::Cat(const Cat& other)
{
	this->brain = new Brain(*other.brain);
	this->type = other.type;
	std::cout << "Cat Copy Constructor Called" << std::endl;
}

Cat& Cat::operator = (const Cat& other)
{
	if(this != &other)
	{
		*(this->brain) = *(other.brain);
		this->type = other.type;
	}
	return(*this);
}

std::string Cat::getType() const
{
	return(this->type);
}
