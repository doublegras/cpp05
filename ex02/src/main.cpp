#include "Bureaucrat.hpp"
#include <iostream>

int main(void) {
  try {
    Bureaucrat linus("Linus", 20);
    std::cout << linus << std::endl;
    Form form("A0", 50, 20);
    std::cout << form << std::endl;
    linus.signForm(form);
    linus.signForm(form);
    std::cout << form << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  try {
    Bureaucrat linus("Linus", 20);
    std::cout << linus << std::endl;
    Form form("A0", 190, 20);
    std::cout << form << std::endl;
    linus.signForm(form);
    linus.signForm(form);
    std::cout << form << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << "\n";

  try {
    Bureaucrat linus("Linus", 70);

    std::cout << linus << std::endl;
    Form form1("A1", 50, 20);
    Form form2(form1);
    std::cout << form1 << std::endl;
    linus.signForm(form1);
    std::cout << form1 << std::endl;
    linus.signForm(form2);
    std::cout << form2 << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
}
