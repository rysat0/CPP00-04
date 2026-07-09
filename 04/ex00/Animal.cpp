#include "Animal.hpp"

void Animal::makeSound() const
{
	std::cout << "Here supposed to be Animal bark" << std::endl;
}

Animal::Animal()
{
	this->type = "Default Animal";
	std::cout << "Animal Default Constructor Called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal Destructor Called" << std::endl;
}

Animal::Animal(std::string type)
{
	this->type = type;
	std::cout << "Animal Assignment Constructor Called" << std::endl;
}

Animal::Animal(const Animal& other)
{
	this->type = other.type;
	std::cout << "Animal Copy Constructor Called";
}

Animal& Animal::operator = (const Animal& other)
{
	if(this != &other)
		this->type = other.type;
	return(*this);
}

std::string Animal::getType() const
{
	return(this->type);
}
