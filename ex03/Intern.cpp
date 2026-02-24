/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmembril <mmembril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 12:04:02 by mmembril          #+#    #+#             */
/*   Updated: 2026/02/24 12:59:43 by mmembril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <string>

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern &copy)
{
    *this = copy;
}

Intern &Intern::operator=(const Intern &copy)
{
    if (this != &copy)
        *this = copy;
    return *this;
}


AForm *Intern::makeForm(const std::string &formName, const std::string &formTarget)
{
    std::string names[3] = {
        "robotomy request",
        "presidential pardon",
        "shrubbery creation"
    };

    AForm *(Intern::*functions[3])(const std::string &target) const  = {
        &Intern::createRobotomyRequest,
        &Intern::createPresidentialPardon,
        &Intern::createShrubberyCreation
    };

    for (int i = 0; i < 3; i++)
    {
        if (formName == names[i])
        {
            AForm *form = (this->*functions[i])(formTarget);
            std::cout << "Intern creates " << form->getName() << std::endl;
            return form;
        }
    }
    throw Intern::InvalidFormException();
}

const char *Intern::InvalidFormException::what() const throw()
{
    return "Invalid form";
}

AForm *Intern::createRobotomyRequest(const std::string &target) const
{
    return new RobotomyRequestForm(target);
}

AForm *Intern::createPresidentialPardon(const std::string &target) const
{
    return new PresidentialPardonForm(target);
}

AForm *Intern::createShrubberyCreation(const std::string &target) const
{
    return new ShrubberyCreationForm(target);
}
