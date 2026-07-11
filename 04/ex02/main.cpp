#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	const Animal* doggo = new Dog();
	const Animal* cattie = new Cat();

	std::cout << cattie->getType() << " " << std::endl;
	std::cout << doggo->getType() << " " << std::endl;
	cattie->makeSound();
	doggo->makeSound();

	delete cattie;
	delete doggo;

	const int size = 4;
	Animal* animals[size];
	int i;

	i = 0;
	while (i < size / 2)
	{
		animals[i] = new Dog();
		i++;
	}

	while (i < size)
	{
		animals[i] = new Cat();
		i++;
	}

	i = 0;
	while (i < size)
	{
		animals[i]->makeSound();
		i++;
	}

	i = 0;
	while (i < size)
	{
		delete animals[i];
		i++;
	}

	Dog dog;
	Dog dogCopy(dog);

	Cat cat;
	Cat catCopy;
	catCopy = cat;

	std::cout << dogCopy.getType() << std::endl;
	std::cout << catCopy.getType() << std::endl;

	return (0);
}
