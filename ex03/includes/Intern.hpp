#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include <string>
class Intern {

private:
public:
  Intern();
  ~Intern();
  Intern(const Intern &i);
  Intern &operator=(const Intern &i);

  AForm *makeForm(std::string form_name, std::string target);

  class FormNotFoundException : public std::exception {
  public:
    virtual const char *what() const throw();
  };
};

#endif
