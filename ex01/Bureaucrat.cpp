#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <exception>
#include <iostream>

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name)
{
    if (grade < 1)
        std::cout << "The grade is too high" << std::endl;
    else if (grade > 150)
        std::cout << "The grade is too low" << std::endl;
    else
     this->_grade = grade;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy)
{
    if (this != &copy)
        this->_grade = copy._grade;
    return *this;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name), _grade(copy._grade) {}

const std::string Bureaucrat::getName() const
{
    return this->_name;
}

int Bureaucrat::getGrade() const
{
    return this->_grade;
}

void Bureaucrat::increment()
{
    if (this->_grade <= 1)
        throw Bureaucrat::GradeTooHighException();
    else
        this->_grade--;
}

void Bureaucrat::decrement()
{
    if (this->_grade >= 150)
        throw Bureaucrat::GradeTooLowException();
    else
        this->_grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b)
{
    os << b.getName() << ": " << b.getGrade() << std::endl;
    return os;
}

void Bureaucrat::signForm(Form &form)
{
    try
    {
        form.beSigned(*this);
        std::cout << "Bureaucrat " << this->getName() << " signed form " 
            << form.getName() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Bureaucrat " << this->getName() << " could not sign form " 
            << form.getName() << " because grade is too low" << std::endl;
    }
}
