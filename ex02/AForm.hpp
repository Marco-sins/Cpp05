

#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"
#include <exception>

class Bureaucrat;

class AForm
{
    private:
        const std::string _name;
        bool _signed;
        const int _gradeSignIt;
        const int _gradeExecuteIt;

        public:
            AForm();
            virtual ~AForm();
            AForm(const std::string &name);
            AForm(const std::string &name, int gradeS, int gradeE);
            AForm(const AForm &copy);
            AForm &operator=(const AForm &copy);

        std::string getName() const;
        bool getSigned() const;
        int getGradeSignIt() const;
        int getGradeExecuteIt() const;

        void beSigned(const Bureaucrat &b);

        virtual void execute(const Bureaucrat &executor) const = 0;

        class GradeTooHighException : public std::exception
        {
            virtual const char *what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            virtual const char *what() const throw();
        };

        class FormNotSigned : public std::exception
        {
            virtual const char *what() const throw();
        };
};

std::ostream &operator<<(std::ostream &os, const AForm &aform);


#endif
