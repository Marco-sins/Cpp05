#include "Form.hpp"

int main(void)
{
    Form form1("Form1");
    Form form2("Form2", 3, 1);
	std::cout << form1;
	std::cout << form2;


	Bureaucrat b1("Marco", 5);
	Bureaucrat b2("Ernesto", 1);
	std::cout << b1;
	std::cout << b2;

	try
	{
		b1.signForm(form1);
		b2.signForm(form1);
		form1.beSigned(b1);

		b1.signForm(form2);
		// A tooLow exception should be thrown
		b2.signForm(form2);
		form2.beSigned(b1);
	}
	catch(std::exception& ex)
	{
		std::cerr << ex.what() << std::endl;
	}


    return 0;
}
