/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmembril <mmembril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 12:03:40 by mmembril          #+#    #+#             */
/*   Updated: 2026/02/24 12:03:41 by mmembril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <csignal>

AForm::AForm() : _name("Default"), _signed(false), _gradeSignIt(150), _gradeExecuteIt(150) {}

AForm::~AForm() {}

AForm::AForm(const std::string &name) : _name(name), _gradeSignIt(150), _gradeExecuteIt(150) {}

AForm::AForm(const std::string &name, int gradeS, int gradeE) : _name(name), _signed(false), _gradeSignIt(gradeS), _gradeExecuteIt(gradeE)
{
    if (gradeE < 1 || gradeS < 1)
        AForm::GradeTooHighException();
    else if (gradeE > 150 || gradeS > 150)
        AForm::GradeTooLowException();
}

AForm::AForm(const AForm &copy) : _name(copy._name), _signed(copy._signed), _gradeSignIt(copy._gradeSignIt), _gradeExecuteIt(copy._gradeExecuteIt) {}

AForm &AForm::operator=(const AForm &copy)
{
    if (this != &copy)
        this->_signed = copy._signed;
    return *this;
}

std::string AForm::getName() const
{
    return this->_name;
}

bool AForm::getSigned() const
{
    return this->_signed;
}

int AForm::getGradeSignIt() const
{
    return this->_gradeSignIt;
}

int AForm::getGradeExecuteIt() const
{
    return this->_gradeExecuteIt;
}

void AForm::beSigned(const Bureaucrat &b)
{
    if (b.getGrade() > this->_gradeSignIt)
        throw AForm::GradeTooLowException();
    else
        this->_signed = true;
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

const char *AForm::FormNotSigned::what() const throw()
{
    return "Form it not signed";
}

std::ostream &operator<<(std::ostream &os, const AForm &aform)
{
    os << aform.getName() << ", form grade to sign " << aform.getGradeSignIt()
        << ", form grade to execute " << aform.getGradeExecuteIt() << ", form is ";
    if (aform.getSigned())
        os << "signed";
    else
     os << "not signed";
    os << std::endl;
    return os;
}
