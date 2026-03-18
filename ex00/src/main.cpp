#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

void	testAnimal()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete(meta);
	delete(j);
	delete(i);
}

void	testWrongAnimal()
{
	const WrongAnimal* meta = new WrongAnimal();
	const WrongAnimal* i = new WrongCat();
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	meta->makeSound();
	delete(meta);
	delete(i);
}


void	draw_separation(void)
{
	std::cout	<< "\n\n"
				<< "\033[37m-=-=-=-=-=-=-=-=-=-"	<< std::endl
				<< "-=TEST  SEPARATOR=-"			<< std::endl
				<< "-=-=-=-=-=-=-=-=-=-\033[0m"
				<< "\n\n"
				<<std::endl;
}

//the difference between animal and wrong animal is the virtual in makeSound
//with polymorphism if no virtual, the parent functions will be called
int	main() {
	testAnimal();
	draw_separation();
	testWrongAnimal();
}
