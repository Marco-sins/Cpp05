/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmembril <mmembril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 12:03:35 by mmembril          #+#    #+#             */
/*   Updated: 2026/02/24 12:03:36 by mmembril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string _name;
        bool _signed;
        const int _gradeSignIt;
        const int _gradeExecuteIt;

        public:
            Form();
            ~Form();
            Form(const std::string &name);
            Form(const std::string &name, int gradeS, int gradeE);
            Form(const Form &copy);
            Form &operator=(const Form &copy);

        std::string getName() const;
        bool getSigned() const;
        int getGradeSignIt() const;
        int getGradeExecuteIt() const;

        void beSigned(const Bureaucrat &b);

        class GradeTooHighException : public std::exception
        {
            virtual const char *what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            virtual const char *what() const throw();
        };
};

std::ostream &operator<<(std::ostream &os, const Form &form);


#endif
