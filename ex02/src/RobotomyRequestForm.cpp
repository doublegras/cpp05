#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(std::string target)
    : AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &s)
    : AForm(s.getName(), 72, 45) {
  *this = s;
}

RobotomyRequestForm &
RobotomyRequestForm::operator=(const RobotomyRequestForm &s) {
  _target = s._target;
  setIsSigned(s.isSigned());
  return (*this);
}

void RobotomyRequestForm::executeForm() const {
  int x = rand() % 2;

  if (!x) {
    std::cout << "The robotomy on " << _target << " failed..." << std::endl;
    return;
  }
  std::cout << "** "
               "ZzZHhZHhZHZhZhZHZHZHhZhZHHZHhzZhzZhhhZHHzhhZHHZhZHhZHhhzZhzhHZh"
               "ZHHZHhzHzhhzhHzhHZHhzHzhHZhzhzhhzHZHhHzhhzHhzZzZHhZHhZHZhZhZHZH"
               "ZHhZhZHHZH... **"
            << std::endl;
  std::cout << _target << " has been robotomized." << std::endl;
}
