#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cmath>

class WrongAnimal
{
	protected:
		std::string type;

	public:
		WrongAnimal();
		virtual ~WrongAnimal();
		WrongAnimal(std::string type);
		WrongAnimal(const WrongAnimal& other);
		WrongAnimal& operator = (const WrongAnimal& other);

		void makeSound() const;
		std::string getType() const;
};

# endif
