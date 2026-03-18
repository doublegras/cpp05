#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(std::string name, int grade)
    : _name(name), _grade(grade) {

  std::cout << "Creating Bureaucrate " << _name << " with grade " << _grade
            << "..." << std::endl;

  if (_grade < 1) {
    throw GradeTooHighException();
  } else if (_grade > 150) {
    throw GradeTooLowException();
  }
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat &b) : _name(b.getName()) {
  std::cout << "Trying to copy " << b.getName() << " with grade "
            << b.getGrade() << "..." << std::endl;
  *this = b;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &b) {
  if (this == &b)
    return *this;
  this->_grade = b.getGrade();
  return *this;
}

std::string Bureaucrat::getName() const { return _name; }

int Bureaucrat::getGrade() const { return (_grade); }

void Bureaucrat::increm() {
  std::cout << "Trying to increase " << _name << "'s grade..." << std::endl;
  if (_grade == 1) {
    throw GradeTooHighException();
  }
  _grade--;
  std::cout << _name << "'s grade is now " << _grade << std::endl;
}

void Bureaucrat::decrem() {
  std::cout << "Trying to decrease " << _name << "'s grade..." << std::endl;
  if (_grade == 150) {
    throw GradeTooLowException();
  }
  _grade++;
  std::cout << _name << "'s grade is now " << _grade << std::endl;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
  return "\033[31mCatched : grade too high\033[0m";
};

const char *Bureaucrat::GradeTooLowException::what() const throw() {
  return "\033[31mCatched : grade too low\033[0m";
};

std::ostream &operator<<(std::ostream &stream, Bureaucrat &b) {
  stream << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
  return stream;
}
