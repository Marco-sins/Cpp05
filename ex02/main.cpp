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

        b1.signForm(s1);
        b1.executeForm(s1);
    
  		b1.signForm(r1);
  		b1.executeForm(r1);
    
        b1.signForm(p1);
        b1.executeForm(p1);

  		b2.signForm(p1);
    
   	}
   	catch(const std::exception& ex)
   	{
  		std::cout << ex.what() << std::endl;
   	}
    return 0;
}