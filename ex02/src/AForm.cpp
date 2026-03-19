#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

AForm::AForm(std::string name, int sign, int exec)
    : _name(name), _gradeRequiredToSign(sign), _gradeRequiredToExec(exec),
      _signed(false) {
  std::cout << "Creating form " << _name << " (grades " << sign << ", " << exec
            << ")..." << std::endl;
  if (sign < 1 || exec < 1) {
    throw GradeTooHighException();
  } else if (sign > 150 || exec > 150) {
    throw GradeTooLowException();
  }
}

AForm::~AForm() {}

AForm::AForm(const AForm &f)
    : _name(f.getName()), _gradeRequiredToSign(f.gradeRequiredToSign()),
      _gradeRequiredToExec(f.gradeRequiredToExec()) {
  *this = f;
  std::cout << "AForm " << f.getName() << " copied" << std::endl;
}

AForm &AForm::operator=(const AForm &f) {
  if (this == &f)
    return (*this);
  this->_signed = f.isSigned();
  return *this;
}

std::string AForm::getName() const { return _name; }

bool AForm::isSigned() const { return _signed; }

int AForm::gradeRequiredToSign() const { return _gradeRequiredToSign; }

int AForm::gradeRequiredToExec() const { return _gradeRequiredToExec; }

const char *AForm::GradeTooHighException::what() const throw() {
  return "\033[31mform grade too high\033[0m";
}

const char *AForm::GradeTooLowException::what() const throw() {
  return "\033[31mform grade too low\033[0m";
}

const char *AForm::AlreadySignedException::what() const throw() {
  return "\033[31mform already signed\033[0m";
}

const char *AForm::NotSignedException::what() const throw() {
  return "\033[31mform isn't signed\033[0m";
}

void AForm::beSigned(Bureaucrat &b) {

  if (b.getGrade() > _gradeRequiredToSign)
    throw GradeTooLowException();
  else if (_signed)
    throw AlreadySignedException();
  else if (b.getGrade() <= _gradeRequiredToSign)
    _signed = true;
}

void AForm::execute(Bureaucrat const &executor) const {

  if (executor.getGrade() > this->gradeRequiredToExec())
    throw GradeTooLowException();
  if (!this->isSigned())
    throw NotSignedException();
  try {
    executeForm();
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }
}

std::ostream &operator<<(std::ostream &stream, AForm &f) {

  stream << "______________________________\n|" << std::endl;
  if (f.isSigned()) {
    stream << "| AForm \"" << f.getName() << "\" (signed) : \n";
  } else {
    stream << "| AForm \"" << f.getName() << "\" (not signed) : \n";
  }
  stream << "| Grade to sign : " << f.gradeRequiredToSign() << "\n"
         << "| Grade to exec : " << f.gradeRequiredToExec() << std::endl;
  stream << "______________________________" << std::endl;
  return stream;
}
