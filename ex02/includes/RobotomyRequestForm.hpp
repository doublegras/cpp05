#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
class RobotomyRequestForm : public AForm {
public:
  RobotomyRequestForm(std::string target);
  virtual ~RobotomyRequestForm();
  RobotomyRequestForm(const RobotomyRequestForm &f);
  RobotomyRequestForm &operator=(const RobotomyRequestForm &f);

  class FileOpeningException : public std::exception {
  public:
    virtual const char *what() const throw();
  };

  void executeForm() const;

private:
  std::string _target;
  RobotomyRequestForm(void);
};

#endif
