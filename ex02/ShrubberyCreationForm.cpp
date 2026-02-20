#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>
#include <ostream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy), _target(copy._target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
    if (this != &copy)
        this->_target = copy._target;
    return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat &b) const
{
    if (b.getGrade() > this->getGradeExecuteIt())
        throw AForm::GradeTooLowException();
    std::ofstream file;
    file.open((_target + "_shrubbery").c_str());
    file << "       ^       \n"
    "      / \\      \n"
    "     /   \\     \n"
    "    /_____\\    \n"
    "   /       \\   \n"
    "  /_________\\  \n"
    "      | |      \n"
    "      |_|      \n";
}

std::ostream &operator<<(std::ostream &os, const ShrubberyCreationForm &form)
{
    os << form.getName() << " is a ShrubberyCreationForm with a grade to sign of " << form.getGradeSignIt()
     << " and a grade to execute of " << form.getGradeExecuteIt() << std::endl;
     return os;
}
