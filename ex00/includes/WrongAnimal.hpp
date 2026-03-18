#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP

# include <iostream>
# include <iomanip>
# include <string>

class WrongAnimal
{
	protected:
		std::string	_type;
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal &wrong_animal);
		virtual ~WrongAnimal();
		WrongAnimal& operator=(const WrongAnimal &wrong_animal);
		void	makeSound() const;
		std::string	getType() const;
};

#endif
