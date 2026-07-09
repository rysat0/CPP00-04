#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat();
		virtual ~Cat();
		Cat(std::string type);
		Cat(const Cat& other);
		Cat& operator = (Cat& other);

		void makeSound() const;
		std::string getType() const;
};

#endif
