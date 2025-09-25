#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat() : name("default"), grade(150)
{
}
Bureaucrat::Bureaucrat(const std::string& n, int g) : name(n)
{
    if (g < 1)
		throw GradeTooHighException();
	else if (g > 150)
		throw GradeTooLowException();
	else
		grade = g;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade)
{
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
		grade = other.grade;	
	return (*this);
}
Bureaucrat::~Bureaucrat() {}

const std::string& Bureaucrat::getName() const { return name; }
int Bureaucrat::getGrade() const { return grade; }

void Bureaucrat::incrementGrade() {
    if (grade <= 1) 
        throw GradeTooHighException();
    grade--;
}
void Bureaucrat::decrementGrade() {
    if (grade >= 150)
        throw GradeTooLowException();
    grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() 
{ return "Grade too high"; }
const char* Bureaucrat::GradeTooLowException::what() const throw() 
{ return "Grade too low"; }

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return os;
}
