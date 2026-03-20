#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
class PresidentialPardonForm : public AForm {
public:
  PresidentialPardonForm(std::string target);
  virtual ~PresidentialPardonForm();
  PresidentialPardonForm(const PresidentialPardonForm &f);
  PresidentialPardonForm &operator=(const PresidentialPardonForm &f);

  class FileOpeningException : public std::exception {
  public:
    virtual const char *what() const throw();
  };

  void executeForm() const;

private:
  std::string _target;
  PresidentialPardonForm(void);
};

#endif
