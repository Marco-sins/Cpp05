#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <csignal>

Form::Form() : _name("Default"), _signed(false), _gradeSignIt(150), _gradeExecuteIt(150) {}

Form::~Form() {}

Form::Form(const std::string &name) : _name(name), _gradeSignIt(150), _gradeExecuteIt(150) {}

Form::Form(const std::string &name, int gradeS, int gradeE) : _name(name), _signed(false), _gradeSignIt(gradeS), _gradeExecuteIt(gradeE)
{
    if (gradeE < 1 || gradeS < 1)
        Form::GradeTooHighException();
    else if (gradeE > 150 || gradeS > 150)
        Form::GradeTooLowException();
}

Form::Form(const Form &copy) : _name(copy._name), _signed(copy._signed), _gradeSignIt(copy._gradeSignIt), _gradeExecuteIt(copy._gradeExecuteIt) {}

Form &Form::operator=(const Form &copy)
{
    if (this != &copy)
        this->_signed = copy._signed;
    return *this;
}

std::string Form::getName() const
{
    return this->_name;
}

bool Form::getSigned() const
{
    return this->_signed;
}

int Form::getGradeSignIt() const
{
    return this->_gradeSignIt;
}

int Form::getGradeExecuteIt() const
{
    return this->_gradeExecuteIt;
}

void Form::beSigned(const Bureaucrat &b)
{
    if (b.getGrade() > this->_gradeSignIt)
        throw Form::GradeTooLowException();
    else
        this->_signed = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
    os << form.getName() << ", form grade to sign " << form.getGradeSignIt()
        << ", form grade to execute " << form.getGradeExecuteIt() << ", form is ";
    if (form.getSigned())
        os << "signed";
    else
     os << "not signed";
    os << std::endl;
    return os;
}
