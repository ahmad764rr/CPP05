#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequest", 72, 45), target("default") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& t)
    : AForm("RobotomyRequest", 72, 45), target(t) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other), target(other.target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        target = other.target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const {
    if (!getIsSigned()) throw NotSignedException();
    if (executor.getGrade() > getExecGrade()) throw GradeTooLowException();

    std::cout << "Bzzzzz drilling noises...\n";
    srand(time(0));
    if (rand() % 2)
        std::cout << target << " has been robotomized successfully!\n";
    else
        std::cout << "Robotomy failed on " << target << "...\n";
}