#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("default"), isSigned(false), signGrade(150), execGrade(150) {}

AForm::AForm(const std::string& n, int s, int e)
    : name(n), isSigned(false), signGrade(s), execGrade(e) {
    if (s < 1 || e < 1) throw GradeTooHighException();
    if (s > 150 || e > 150) throw GradeTooLowException();
}

AForm::~AForm() {}

AForm::AForm(const AForm& o)
    : name(o.name), isSigned(o.isSigned), signGrade(o.signGrade), execGrade(o.execGrade) {}

AForm& AForm::operator=(const AForm& o) {
    if (this != &o) isSigned = o.isSigned;
    return *this;
}

const std::string& AForm::getName() const { return name; }
bool AForm::getIsSigned() const { return isSigned; }
int AForm::getSignGrade() const { return signGrade; }
int AForm::getExecGrade() const { return execGrade; }

void AForm::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > signGrade) throw GradeTooLowException();
    isSigned = true;
}

const char* AForm::GradeTooHighException::what() const throw() { return "Form grade too high"; }
const char* AForm::GradeTooLowException::what() const throw() { return "Form grade too low"; }
const char* AForm::NotSignedException::what() const throw() { return "Form not signed"; }

std::ostream& operator<<(std::ostream& os, const AForm& f) {
    os << "Form " << f.getName()
       << " (signGrade " << f.getSignGrade()
       << ", execGrade " << f.getExecGrade()
       << ") signed=" << f.getIsSigned();
    return os;
}