#include "WrongAnimal.hpp"

void WrongAnimal::makeSound() const
{
	std::cout << "Here supposed to be WrongAnimal bark" << std::endl;
}

WrongAnimal::WrongAnimal()
{
	this->type = "Default WrongAnimal";
	std::cout << "WrongAnimal Default Constructor Called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal Destructor Called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type)
{
	this->type = type;
	std::cout << "WrongAnimal Assignment Constructor Called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
	this->type = other.type;
	std::cout << "WrongAnimal Copy Constructor Called" << std::endl;
}

WrongAnimal& WrongAnimal::operator = (const WrongAnimal& other)
{
	if(this != &other)
		this->type = other.type;
	return(*this);
}

std::string WrongAnimal::getType() const
{
	return(this->type);
}
