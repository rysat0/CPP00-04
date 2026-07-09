#include "Dog.hpp"

void Dog::makeSound() const
{
	std::cout << "bow wow!" << std::endl;
}

Dog::Dog()
{
	this->type = "Dog";
	std::cout << "Dog Default Constructor Called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog Destructor Called" << std::endl;
}

Dog::Dog(std::string type)
{
	this->type = type;
	std::cout << "Dog Assignment Constructor Called" << std::endl;
}

Dog::Dog(const Dog& other)
{
	this->type = other.type;
	std::cout << "Dog Copy Constructor Called" << std::endl;
}

Dog& Dog::operator = (const Dog& other)
{
	if(this != &other)
		this->type = other.type;
	return(*this);
}

std::string Dog::getType() const
{
	return(this->type);
}
