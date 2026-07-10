#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"



int main()
{
	const Animal* meta = new Animal();
	const Animal* doggo = new Dog();
	const Animal* catto = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	const WrongAnimal* wrong = new WrongCat();

	std::cout << wrong->getType() << std::endl;
	wrong->makeSound();

	WrongCat directWrongCat;
	directWrongCat.makeSound();

	Dog dog;
	Dog dogCopy(dog);
	Cat cat;
	Cat catCopy;

	catCopy = cat;
	std::cout << dogCopy.getType() << std::endl;
	std::cout << catCopy.getType() << std::endl;

	delete wrong;
	delete meta;
	delete j;
	delete i;

	return 0;
}
