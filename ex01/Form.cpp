#include "Form.hpp"

Form::Form(const std::string& n, int s, int e) 
    : name(n), isSigned(false), signGrade(s), execGrade(e) {
    if (s < 1 || e < 1) throw GradeTooHighException();
    if (s > 150 || e > 150) throw GradeTooLowException();
}

Form::~Form() {}

Form::Form(const Form& o) 
    : name(o.name), isSigned(o.isSigned), signGrade(o.signGrade), execGrade(o.execGrade) {}

Form& Form::operator=(const Form& o) {
    if (this != &o) isSigned = o.isSigned;
    return *this;
}

const std::string& Form::getName() const { return name; }
bool Form::getIsSigned() const { return isSigned; }
int Form::getSignGrade() const { return signGrade; }
int Form::getExecGrade() const { return execGrade; }

void Form::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > signGrade) throw GradeTooLowException();
    isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw() { return "Form grade too high"; }
const char* Form::GradeTooLowException::what() const throw() { return "Form grade too low"; }

std::ostream& operator<<(std::ostream& os, const Form& f) {
    os << "Form " << f.getName() 
       << " (signGrade " << f.getSignGrade()
       << ", execGrade " << f.getExecGrade()
       << ") signed=" << f.getIsSigned();
    return os;
}
