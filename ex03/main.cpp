#include "AForm.hpp"
#include "Intern.hpp"

int main()
{
    try
   	{
        Intern intern;
        AForm *form;
        form = intern.makeForm("robotomy request", "target");

        delete form;
   	}
   	catch(const std::exception& ex)
   	{
  		std::cout << ex.what() << std::endl;
   	}
    return 0;
}
