#ifndef FORM_HPP
#define FORM_HPP

// #include "Bureaucrat.hpp"
#include <string>

class Bureaucrat;
class AForm {
public:
  AForm(std::string name, int sign, int exec);
  virtual ~AForm();
  AForm(const AForm &form);
  AForm &operator=(const AForm &form);

  std::string getName() const;
  bool isSigned() const;
  int gradeRequiredToSign() const;
  int gradeRequiredToExec() const;
  void execute(Bureaucrat const &executor) const;
  virtual void executeForm() const = 0;

  void beSigned(Bureaucrat &b);

  class GradeTooHighException : public std::exception {
  public:
    virtual const char *what() const
        throw(); // throw() tells the compiler that this method wont throw any
                 // exception
  };

  class GradeTooLowException : public std::exception {
  public:
    virtual const char *what() const
        throw(); // throw() tells the compiler that this method wont throw any
                 // exception
  };

  class AlreadySignedException : public std::exception {
  public:
    virtual const char *what() const
        throw(); // throw() tells the compiler that this method wont throw any
                 // exception
  };

  class NotSignedException : public std::exception {
  public:
    virtual const char *what() const
        throw(); // throw() tells the compiler that this method wont throw any
                 // exception
  };

private:
  const std::string _name;
  const int _gradeRequiredToSign;
  const int _gradeRequiredToExec;
  bool _signed;
};

std::ostream &operator<<(std::ostream &stream, AForm &f);

#endif
