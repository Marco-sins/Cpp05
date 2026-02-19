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

        // Must be throw an exception tooHigh
        Bureaucrat b4("Error", 0);

        // Must be throw an exception tooHigh
        b2.increment();

        // Must be throw an exception tooLow
        b1.decrement();
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }


    return 0;
}
