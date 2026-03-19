#ifndef FORM_HPP
#define FORM_HPP

// #include "Bureaucrat.hpp"
#include <string>

class Bureaucrat;
class Form {
public:
  Form(std::string name, int sign, int exec);
  ~Form();
  Form(const Form &form);
  Form &operator=(const Form &form);

  std::string getName() const;
  bool isSigned() const;
  int gradeRequiredToSign() const;
  int gradeRequiredToExec() const;

  void beSigned(Bureaucrat &b);
  void execute(Bureaucrat const &executor) const;

  class GradeTooHighException : public std::exception {
  public:
    virtual const char *what() const
        throw(); // throw() tells the compiler that this
                 // method wont throw any exception
  };

  class GradeTooLowException : public std::exception {
  public:
    virtual const char *what() const
        throw(); // throw() tells the compiler that this
                 // method wont throw any exception
  };

  class AlreadySignedException : public std::exception {
  public:
    virtual const char *what() const
        throw(); // throw() tells the compiler that this
                 // method wont throw any exception
  };

private:
  const std::string _name;
  const int _gradeRequiredToSign;
  const int _gradeRequiredToExec;
  bool _signed;
};

std::ostream &operator<<(std::ostream &stream, Form &f);

#endif
