#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

// std::ostream &operator<<(std::ostream &stream, Bureaucrat &b);
// std::ostream &operator<<(std::ostream &stream, AForm &f);

int main(void) {
  std::cout << std::endl;
  try {
    Bureaucrat linus("Linus", 200);
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << std::endl;
  std::cout << "Shrubbery test :" << std::endl;
  std::cout << std::endl;
  try {
    Bureaucrat linus("Linus", 20);
    std::cout << linus << std::endl;
    Bureaucrat bill("Bill", 147);
    std::cout << bill << std::endl;
    Bureaucrat steve("Steve", 137);
    std::cout << steve << std::endl;
    ShrubberyCreationForm form("home");

    std::cout << form << std::endl;
    linus.executeForm(form);
    linus.signForm(form);
    bill.signForm(form);
    linus.executeForm(form);
    bill.executeForm(form);
    steve.executeForm(form);
    std::cout << form << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << std::endl;
  std::cout << "Robotomy test :" << std::endl;
  std::cout << std::endl;
  try {
    Bureaucrat linus("Linus", 20);
    std::cout << linus << std::endl;
    Bureaucrat steve("Steve", 137);
    std::cout << steve << std::endl;
    RobotomyRequestForm form(steve.getName());
    std::cout << form << std::endl;
    linus.signForm(form);
    linus.executeForm(form);
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << std::endl;
  std::cout << "Presidential test :" << std::endl;
  std::cout << std::endl;
  try {
    Bureaucrat linus("Linus", 5);
    Bureaucrat steve("Steve", 137);
    PresidentialPardonForm form(steve.getName());
    std::cout << form << std::endl;
    steve.signForm(form);
    linus.signForm(form);
    linus.executeForm(form);
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << "\n";
}
