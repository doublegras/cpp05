#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>
#include <ostream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &s)
    : AForm(s.getName(), 145, 137) {
  *this = s;
}

ShrubberyCreationForm &
ShrubberyCreationForm::operator=(const ShrubberyCreationForm &s) {
  _target = s._target;
  setIsSigned(s.isSigned());
  return (*this);
}

const char *ShrubberyCreationForm::FileOpeningException::what() const throw() {
  return "\033[31mcouldn't open file\033[0m";
}

void ShrubberyCreationForm::executeForm() const {

  std::string filename(_target);
  filename.append("_shrubbery");

  std::ofstream output(filename.c_str());

  if (!output.is_open())
    throw FileOpeningException();

  output << "                      ___" << std::endl
         << "                _,-'\"\"   \"\"\"\"`--." << std::endl
         << "             ,-'          __,,-- \\\\" << std::endl
         << "           ,'    __,--\"\"\"\"dF      )" << std::endl
         << "          /   .-\"Hb_,--\"\"dF      /" << std::endl
         << "        ,'       _Hb ___dF\"-._,-'" << std::endl
         << "      ,'      _,-\"\"\"\"   \"\"--..__" << std::endl
         << "     (     ,-'                  `." << std::endl
         << "      `._,'     _   _             ;" << std::endl
         << "       ,'     ,' `-'Hb-.___..._,-'" << std::endl
         << "       \\\\    ,'\"Hb.-'HH`-.dHF\"" << std::endl
         << "        `--'   \"Hb  HH  dF\"" << std::endl
         << "                \"Hb HH dF" << std::endl
         << "                 \"HbHHdF" << std::endl
         << "                  |HHHF" << std::endl
         << "                  |HHH|" << std::endl
         << "                  |HHH|" << std::endl
         << "                  |HHH|" << std::endl
         << "                  |HHH|" << std::endl
         << "                  dHHHb" << std::endl
         << "                .dFd|bHb.               o" << std::endl
         << "      o       .dHFdH|HbTHb.          o /" << std::endl
         << "\\\\  Y  |  \\\\__,dHHFdHH|HHhoHHb.__Krogg  Y" << std::endl
         << "##########################################" << std::endl;

  output << std::endl;
  output << std::endl;

  output << "              _{\\ _{\\{\\/}/}/}__" << std::endl
         << "             {/{/\\}{/{/\\}(\\}{/\\} _" << std::endl
         << "            {/{/\\}{/{/\\}(_)\\}{/{/\\}  _" << std::endl
         << "         {\\{/(\\}\\}{/{/\\}\\}{/){/\\}\\} /\\}" << std::endl
         << "        {/{/(_)/}{\\{/)}{\\(_){/}/}/}/}" << std::endl
         << "       _{\\{/{/{\\{/{/(_)/}/}/}{\\(/}/}/}" << std::endl
         << "      {/{/{\\{\\{(/}{\\{\\/}/}{\\}(_){\\/}\\}" << std::endl
         << "      _{\\{/{\\{/(_)\\}/}{/{/{/\\}\\})\\}{/\\}" << std::endl
         << "     {/{/{\\{\\(/}{/{\\{\\{\\/})/}{\\(_)/}/}\\}" << std::endl
         << "      {\\{\\/}(_){\\{\\{\\/}/}(_){\\/}{\\/}/})/}" << std::endl
         << "       {/{\\{\\/}{/{\\{\\{\\/}/}{\\{\\/}/}\\}(_)" << std::endl
         << "      {/{\\{\\/}{/){\\{\\{\\/}/}{\\{(/}/}\\}/}" << std::endl
         << "       {/{\\{\\/}(_){\\{\\{(/}/}{\\(_)/}/}\\}" << std::endl
         << "         {/({/{\\{/{\\{\\/}(_){\\/}/}\\}/}(\\}" << std::endl
         << "          (_){/{\\/}{\\{\\/}/}{\\{\\)/}/}(_)" << std::endl
         << "            {/{/{\\{\\/}{/{\\{\\{(_)/}" << std::endl
         << "             {/{\\{\\{\\/}/}{\\{\\\\}/}" << std::endl
         << "              {){/ {\\/}{\\/} \\}\\}" << std::endl
         << "              (_)  \\.-'.-/" << std::endl
         << "          __...--- |'-.-'| --...__" << std::endl
         << "   _...--\"   .-'   |'-.-'|  ' -.  \"\"--..__" << std::endl
         << " -\"    ' .  . '    |.'-._| '  . .  '   jro" << std::endl
         << " .  '-  '    .--'  | '-.'|    .  '  . '" << std::endl
         << "          ' ..     |'-_.-|" << std::endl
         << "  .  '  .       _.-|-._ -|-._  .  '  ." << std::endl
         << "              .'   |'- .-|   '." << std::endl
         << "  ..-'   ' .  '.   `-._.-�   .'  '  - ." << std::endl
         << "   .-' '        '-._______.-'     '  ." << std::endl
         << "        .      ~," << std::endl;

  std::cout << filename << " created!" << std::endl;
  output.close();
}
