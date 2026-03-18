#include "Cat.hpp"

Cat::Cat() {
	std::cout << "Cat Default constructor" << std::endl;
	_type = "Cat";
}

Cat::~Cat(void) {
	std::cout << "Cat Destructor" << std::endl;
}

Cat::Cat(const Cat &cat) :Animal(cat)
{
	std::cout << "Cat Copy constructor" << std::endl;
	_type = cat._type;
}

Cat& Cat::operator=(const Cat &cat)
{
	std::cout << "Cat Copy assignment operator" << std::endl;
	if (this == &cat) {
		std::cout << "self assignement..." << std::endl;
		return *this;
	}
	_type = cat._type;
    return *this;
}

void	Cat::makeSound() const {
	std::cout << "*cat sound*" << std::endl;
}
