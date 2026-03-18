#include "WrongCat.hpp"

WrongCat::WrongCat() {
	std::cout << "WrongCat Default constructor called" << std::endl;
	_type = "WrongCat";
}

WrongCat::~WrongCat(void) {
	std::cout << "WrongCat Destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &wrong_cat) :WrongAnimal(wrong_cat) {
	std::cout << "WrongCat Copy constructor called" << std::endl;
	_type = wrong_cat._type;
}

WrongCat& WrongCat::operator=(const WrongCat &wrong_cat) {
	std::cout << "WrongCat Copy assignment operator called" << std::endl;
	if (this == &wrong_cat)
	{
		std::cout << "self assignement..." << std::endl;
		return *this;
	}
	_type = wrong_cat._type;
    return *this;
}

void	WrongCat::makeSound() const {
	std::cout << "*wrong cat sound*" << std::endl;
}
