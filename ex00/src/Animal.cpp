#include "Animal.hpp"

Animal::Animal() {
	std::cout << "Animal default constructor" << std::endl;
	_type = "Animal";
}

Animal::~Animal() {
	std::cout << "Animal destructor" << std::endl;
}

Animal::Animal(const Animal &animal) {
	std::cout << "Animal copy constructor" << std::endl;
	_type = animal._type;
}

Animal& Animal::operator=(const Animal &animal) {
	std::cout << "Animal Copy assignment" << std::endl;
	if (this == &animal) {
		std::cout << "self assignement..." << std::endl;
		return *this;
	}
	_type = animal._type;
    return *this;
}

void	Animal::makeSound() const {
	std::cout << "*generic animmal sound*" << std::endl;
}

std::string Animal::getType() const {
	return _type;
}
