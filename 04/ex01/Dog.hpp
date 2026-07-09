#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"


class Dog : public Animal
{

	protected:
		Brain *brain;

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
