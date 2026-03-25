#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

Intern::Intern() { std::cout << "Creating a new intern" << std::endl; }

Intern::~Intern() { std::cout << "Deleting intern" << std::endl; }

Intern::Intern(const Intern &intern) { *this = intern; }

Intern &Intern::operator=(const Intern &intern) {
  (void)intern;
  return (*this);
}

const char *Intern::FormNotFoundException::what() const throw() {
  return "\033[31mform doesn't exist\033[0m";
}

AForm *createShrubbery(std::string target) {
  return (new ShrubberyCreationForm(target));
}

AForm *createRobotomy(std::string target) {
  return (new RobotomyRequestForm(target));
}

AForm *createPresidential(std::string target) {
  return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(std::string form_name, std::string target) {
  std::string availableForm[3] = {
      "ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
  AForm *(*list[3])(std::string target) = {&createShrubbery, &createRobotomy,
                                           &createPresidential};

  std::cout << "Intern tries to create form \"" << form_name << "\""
            << std::endl;

  for (int i = 0; i < 3; i++) {
    if (availableForm[i] == form_name) {
      std::cout << "Intern creates " << form_name << std::endl;
      return (list[i](target));
    }
  }
  throw FormNotFoundException();
}
