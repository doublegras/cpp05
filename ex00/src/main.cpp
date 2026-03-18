#include "Bureaucrat.hpp"
#include <iostream>

int main(void) {
  try {
    Bureaucrat linus("Linus", 20);
    std::cout << linus << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << "\n";

  try {
    Bureaucrat bill("Bill", 151);
    std::cout << bill << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << "\n";

  try {
    Bureaucrat steve("Steve", 0);
    std::cout << steve << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << "\n";

  try {
    Bureaucrat alpha("Alpha", 1);
    std::cout << alpha << std::endl;
    alpha.increm();
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << "\n";

  try {
    Bureaucrat beta("Beta", 130);
    std::cout << beta << std::endl;
    beta.increm();
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << "\n";

  try {
    Bureaucrat zeta("Zeta", 149);
    std::cout << zeta << std::endl;
    zeta.decrem();
    zeta.decrem();
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << "\n";

  try {
    Bureaucrat igor("Igor", 148);
    igor.decrem();
    Bureaucrat grichka(igor);
    grichka.decrem();
    grichka.decrem();
    grichka.decrem();
    grichka.decrem();
    grichka.decrem();
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << "\n";
}
