#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{

	protected:
		Brain *brain;

	public:
		Cat();
		virtual ~Cat();
		Cat(std::string type);
		Cat(const Cat& other);
		Cat& operator = (const Cat& other);

		void makeSound() const;
		std::string getType() const;
};

#endif
