/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmembril <mmembril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 12:03:26 by mmembril          #+#    #+#             */
/*   Updated: 2026/02/24 12:11:29 by mmembril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
    try
    {
        Bureaucrat b1("Error", 149);
        Bureaucrat b2("Marco", 2);
        Bureaucrat b3(b2);
        b3 = b1;

        std::cout << "B1: " << b1 << std::endl;
        std::cout << "B2: " << b2 << std::endl;
        std::cout << "B3: " << b3 << std::endl;

        b2.increment();
        b1.decrement();

        std::cout << "B1: " << b1 << std::endl;
        std::cout << "B2: " << b2 << std::endl;

        // A tooHigh exception should be thrown
        Bureaucrat b4("Error", 0);

        // A tooHigh exception should be thrown
        b2.increment();

        // A tooLow exception should be thrown
        b1.decrement();
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }


    return 0;
}
