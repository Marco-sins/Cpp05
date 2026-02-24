/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmembril <mmembril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 12:04:05 by mmembril          #+#    #+#             */
/*   Updated: 2026/02/24 12:04:06 by mmembril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"

#include <exception>
#include <string>

class Intern
{
    private:
        AForm *createRobotomyRequest(const std::string &target) const;
        AForm *createPresidentialPardon(const std::string &target) const;
        AForm *createShrubberyCreation(const std::string &target) const;

    public:
        Intern();
        ~Intern();
        Intern(const Intern &copy);
        Intern &operator=(const Intern &copy);

        AForm *makeForm(const std::string &formName, const std::string &formTarget);

        class InvalidFormException : public std::exception
        {
            virtual const char *what() const throw();
        };
};

#endif
