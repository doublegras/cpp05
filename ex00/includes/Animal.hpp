#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <iomanip>
# include <string>

class Animal {
	protected:
		std::string	_type;
	public:
		Animal();
		Animal(const Animal &animal);
		Animal& operator=(const Animal &animal);
		virtual void	makeSound() const; // specifying const tells that the method cannot change the object state.
		virtual ~Animal(); // destructor should be virtual otherwise the child destructor will never be called if the object is created from Animal *b = new Cat();
		std::string getType() const;
};

# endif
