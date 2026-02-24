/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmembril <mmembril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 12:03:46 by mmembril          #+#    #+#             */
/*   Updated: 2026/02/24 12:51:57 by mmembril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try
   	{
  		ShrubberyCreationForm s1("s1");
  		Bureaucrat b1("b1", 1);
  		Bureaucrat b2("b2", 149);
  		RobotomyRequestForm r1("r1");
  		PresidentialPardonForm p1("p1");

		std::cout << s1 << std::endl;
		std::cout << b1 << std::endl;
		std::cout << b2 << std::endl;
		std::cout << r1 << std::endl;
		std::cout << p1 << std::endl;

        b1.signForm(s1);
        b1.executeForm(s1);
		std::cout << std::endl;
    
  		b1.signForm(r1);
  		b1.executeForm(r1);
		std::cout << std::endl;
		
        b1.signForm(p1);
        b1.executeForm(p1);
		std::cout << std::endl;
		
		// Exception
  		b2.signForm(p1);
    
   	}
   	catch(const std::exception& ex)
   	{
  		std::cout << ex.what() << std::endl;
   	}
    return 0;
}