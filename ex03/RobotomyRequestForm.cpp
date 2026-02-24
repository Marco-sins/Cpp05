/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmembril <mmembril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 12:04:09 by mmembril          #+#    #+#             */
/*   Updated: 2026/02/24 13:12:47 by mmembril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ostream>
#include <string>

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) :  AForm(copy), _target(copy._target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
    if (this != &copy)
        this->_target = copy._target;
    return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat &b) const
{
    if (b.getGrade() > this->getGradeExecuteIt())
        throw AForm::GradeTooLowException();
    if (!this->getSigned())
        throw AForm::FormNotSigned();
    std::cout << "* VRRRRRRR... BZZZZZZZZ... DRILLING NOISES *" << std::endl;
    std::srand(std::time(NULL));
    int ran = std::rand();
    if (ran % 2 == 0)
        std::cout << this->_target << " has been robotomized" << std::endl;
    else
        std::cout << "Failed to robotimize " << this->_target << std::endl;
}

std::ostream &operator<<(std::ostream &os, const RobotomyRequestForm &form)
{
    os << form.getName() << " is a RobotomyRequestForm with a grade to sign of " << form.getGradeSignIt()
     << " and a grade to execute of " << form.getGradeExecuteIt() << std::endl;
     return os;
}
