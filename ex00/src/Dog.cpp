#include "Dog.hpp"

Dog::Dog() {
	std::cout << "Dog Default constructor" << std::endl;
	_type = "Dog";
}

Dog::~Dog(void) {
	std::cout << "Dog Destructor" << std::endl;
}

Dog::Dog(const Dog &cat) :Animal(cat)
{
	std::cout << "Dog Copy constructor" << std::endl;
	_type = cat._type;
}

Dog& Dog::operator=(const Dog &cat)
{
	std::cout << "Dog Copy assignment operator" << std::endl;
	if (this == &cat) {
		std::cout << "self assignement..." << std::endl;
		return *this;
	}
	_type = cat._type;
    return *this;
}

void	Dog::makeSound() const {
	std::cout << "*dog sound*" << std::endl;
}
