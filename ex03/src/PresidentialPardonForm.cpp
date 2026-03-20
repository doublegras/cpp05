
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(std::string target)
    : AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &s)
    : AForm(s.getName(), 25, 5) {
  *this = s;
}

PresidentialPardonForm &
PresidentialPardonForm::operator=(const PresidentialPardonForm &s) {
  _target = s._target;
  setIsSigned(s.isSigned());
  return (*this);
}

void PresidentialPardonForm::executeForm() const {
  std::cout << _target << " has been pardoned by Zaphod Beeblebrox."
            << std::endl;
}
