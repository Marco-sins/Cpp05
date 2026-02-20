
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm(copy), _target(copy._target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
    if (this != &copy)
        this->_target = copy._target;
    return *this;
}

void PresidentialPardonForm::execute(const Bureaucrat &b) const
{
    if (b.getGrade() > this->getGradeExecuteIt())
        throw AForm::GradeTooLowException();
    if (!this->getSigned())
        throw AForm::FormNotSigned();
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

std::ostream &operator<<(std::ostream &os, const PresidentialPardonForm &form)
{
    os << form.getName() << " is a PresidentialPardonForm with a grade to sign of " << form.getGradeSignIt()
     << " and a grade to execute of " << form.getGradeExecuteIt() << std::endl;
     return os;
}
