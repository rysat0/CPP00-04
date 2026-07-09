#include "Cat.hpp"

void Cat::makeSound() const
{
	std::cout << "Myaw Myaow" << std::endl;
}

Cat::Cat()
{
	this->type = "Cat";
	std::cout << "Cat Default Constructor Called" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat Destructor Called" << std::endl;
}

Cat::Cat(std::string type)
{
	this->type = type;
	std::cout << "Cat Assignment Constructor Called" << std::endl;
}

Cat::Cat(const Cat& other)
{
	this->type = other.type;
	std::cout << "Cat Copy Constructor Called";
}

Cat& Cat::operator = (Cat& other)
{
	if(this != &other)
		this->type = other.type;
	return(*this);
}

std::string Cat::getType() const
{
	return(this->type);
}
