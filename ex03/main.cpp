/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmembril <mmembril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 12:04:04 by mmembril          #+#    #+#             */
/*   Updated: 2026/02/24 13:15:00 by mmembril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Intern.hpp"

int main()
{
    try
   	{
        Bureaucrat b("Marco", 1);
        Intern intern;
        AForm *form;
        form = intern.makeForm("robotomy request", "target");
        std::cout << *form << std::endl;
        b.signForm(*form);
        form->execute(b);

        delete form;

        // Intern intern;
        // AForm *form;
        // form = intern.makeForm("shrubbery creation", "target");
        // std::cout << *form << std::endl;
        // b.signForm(*form);
        // form->execute(b);

        // delete form;

        // Intern intern;
        // AForm *form;
        // form = intern.makeForm("presidential pardon", "target");
        // std::cout << *form << std::endl;
        // b.signForm(*form);
        // form->execute(b);

        // delete form;
   	}
   	catch(const std::exception& ex)
   	{
  		std::cout << ex.what() << std::endl;
   	}
    return 0;
}
