#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
class ShrubberyCreationForm : public AForm {
public:
  ShrubberyCreationForm(std::string target);
  virtual ~ShrubberyCreationForm();
  ShrubberyCreationForm(const ShrubberyCreationForm &f);
  ShrubberyCreationForm &operator=(const ShrubberyCreationForm &f);

  class FileOpeningException : public std::exception {
  public:
    virtual const char *what() const throw();
  };

  void executeForm() const;

private:
  std::string _target;
  ShrubberyCreationForm(void);
};

#endif
