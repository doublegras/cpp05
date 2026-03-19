#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

Form::Form(std::string name, int sign, int exec)
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

Form::~Form() {}

Form::Form(const Form &f)
    : _name(f.getName()), _gradeRequiredToSign(f.gradeRequiredToSign()),
      _gradeRequiredToExec(f.gradeRequiredToExec()) {
  *this = f;
  std::cout << "Form " << f.getName() << " copied" << std::endl;
}

Form &Form::operator=(const Form &f) {
  if (this == &f)
    return (*this);
  this->_signed = f.isSigned();
  return *this;
}

std::string Form::getName() const { return _name; }

bool Form::isSigned() const { return _signed; }

int Form::gradeRequiredToSign() const { return _gradeRequiredToSign; }

int Form::gradeRequiredToExec() const { return _gradeRequiredToExec; }

const char *Form::GradeTooHighException::what() const throw() {
  return "\033[31mform grade too high\033[0m";
}

const char *Form::GradeTooLowException::what() const throw() {
  return "\033[31mform grade too low\033[0m";
}

const char *Form::AlreadySignedException::what() const throw() {
  return "\033[31mform already signed\033[0m";
}

void Form::beSigned(Bureaucrat &b) {

  if (b.getGrade() > _gradeRequiredToSign)
    throw GradeTooLowException();
  else if (_signed)
    throw AlreadySignedException();
  else if (b.getGrade() <= _gradeRequiredToSign)
    _signed = true;
}

std::ostream &operator<<(std::ostream &stream, Form &f) {

  stream << "______________________________\n|" << std::endl;
  if (f.isSigned()) {
    stream << "| Form \"" << f.getName() << "\" (signed) : \n";
  } else {
    stream << "| Form \"" << f.getName() << "\" (not signed) : \n";
  }
  stream << "| Grade to sign : " << f.gradeRequiredToSign() << "\n"
         << "| Grade to exec : " << f.gradeRequiredToExec() << std::endl;
  stream << "______________________________" << std::endl;
  return stream;
}
