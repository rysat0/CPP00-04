#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog();
		virtual ~Dog();
		Dog(std::string type);
		Dog(const Dog& other);
		Dog& operator = (const Dog& other);

		void makeSound() const;
		std::string getType() const;
};

#endif
