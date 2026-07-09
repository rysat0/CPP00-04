#include "WrongCat.hpp"

void WrongCat::makeSound() const
{
	std::cout << "prrrrrrrrr" << std::endl;
}

WrongCat::WrongCat()
{
	this->type = "WrongCat";
	std::cout << "WrongCat Default Constructor Called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Destructor Called" << std::endl;
}

WrongCat::WrongCat(std::string type)
{
	this->type = type;
	std::cout << "WrongCat Assignment Constructor Called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other)
{
	this->type = other.type;
	std::cout << "WrongCat Copy Constructor Called" << std::endl;
}

WrongCat& WrongCat::operator = (const WrongCat& other)
{
	if(this != &other)
		this->type = other.type;
	return(*this);
}

std::string WrongCat::getType() const
{
	return(this->type);
}
