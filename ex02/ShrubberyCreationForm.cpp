#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() 
    : AForm("ShrubberyCreation", 145, 137), target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& t)
    : AForm("ShrubberyCreation", 145, 137), target(t) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), target(other.target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        target = other.target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
    if (!getIsSigned()) throw NotSignedException();
    if (executor.getGrade() > getExecGrade()) throw GradeTooLowException();

    std::ofstream ofs((target + "_shrubbery").c_str());
    ofs << "   ccee88oo\n"
           " C8O8O8Q8PoOb o8oo\n"
           "dOB69QO8PdUOpugoO9bD\n";
    ofs.close();
}