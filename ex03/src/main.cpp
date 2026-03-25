#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <unistd.h>

int main(void) {

  Intern someRandomIntern;

  AForm *rrf;

  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;
  try {
    std::cout << "\n" << std::endl;
    rrf = someRandomIntern.makeForm("RaiseRequestForm", "Bender");
    std::cout << "\n" << std::endl;
    rrf = someRandomIntern.makeForm("RobotomyRequestForm", "Bender");
    std::cout << "\n" << std::endl;
    Bureaucrat linus("Linux", 130);
    std::cout << "\n" << std::endl;
    std::cout << linus << std::endl;
    std::cout << "\n" << std::endl;
    linus.signForm(*rrf);
    std::cout << "\n" << std::endl;
    Bureaucrat steve("Steve", 30);
    std::cout << "\n" << std::endl;
    std::cout << steve << std::endl;
    std::cout << "\n" << std::endl;
    steve.signForm(*rrf);
    std::cout << "\n" << std::endl;
    linus.executeForm(*rrf);
    std::cout << "\n" << std::endl;
    steve.executeForm(*rrf);
    std::cout << std::endl;
    delete rrf;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;
  try {
    std::cout << "\n" << std::endl;
    rrf = someRandomIntern.makeForm("RobotomyRequestForm", "Bender");
    std::cout << "\n" << std::endl;
    Bureaucrat linus("Linux", 130);
    std::cout << "\n" << std::endl;
    std::cout << linus << std::endl;
    std::cout << "\n" << std::endl;
    linus.signForm(*rrf);
    std::cout << "\n" << std::endl;
    Bureaucrat steve("Steve", 30);
    std::cout << "\n" << std::endl;
    std::cout << steve << std::endl;
    std::cout << "\n" << std::endl;
    steve.signForm(*rrf);
    std::cout << "\n" << std::endl;
    linus.executeForm(*rrf);
    std::cout << "\n" << std::endl;
    steve.executeForm(*rrf);
    std::cout << std::endl;
    delete rrf;
    std::cout << std::endl;
    std::cout << std::endl;
    AForm *rrf2 = someRandomIntern.makeForm("ShrubberyCreationForm", "home");
    steve.signForm(*rrf2);
    steve.executeForm(*rrf2);
    delete rrf2;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
}
