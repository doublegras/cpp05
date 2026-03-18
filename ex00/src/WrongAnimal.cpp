#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	std::cout << "WrongAnimal Default constructor" << std::endl;
	_type = "WrongAnimal";
}

WrongAnimal::~WrongAnimal(void) {
	std::cout << "WrongAnimal Destructor" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &wrong_animal) {
	std::cout << "WrongAnimal Copy constructor" << std::endl;
	_type = wrong_animal._type;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &wrong_animal) {
	std::cout << "WrongAnimal Copy assignment operator" << std::endl;
	if (this == &wrong_animal)
	{
		std::cout << "self assignement..." << std::endl;
		return *this;
	}
	_type = wrong_animal._type;
    return *this;
}
void	WrongAnimal::makeSound() const {
	std::cout << "*generic wrong animmal sound*" << std::endl;
}

std::string WrongAnimal::getType() const {
	return _type;
}
