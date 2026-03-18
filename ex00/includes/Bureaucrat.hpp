#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <string>
class Bureaucrat {
public:
  Bureaucrat(std::string, int grade);
  ~Bureaucrat();
  Bureaucrat(const Bureaucrat &bureaucrat);
  Bureaucrat &operator=(const Bureaucrat &bureaucrat);
  std::string getName() const;
  int getGrade() const;
  void increm();
  void decrem();
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

private:
  std::string _name;
  int _grade;
};

std::ostream &operator<<(std::ostream &stream, Bureaucrat &b);

#endif
