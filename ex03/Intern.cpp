#include "Intern.hpp"
#include <iostream>

Intern::Intern() {}

Intern::Intern(const Intern& other) {
    (void)other;
}

Intern& Intern::operator=(const Intern& other) {
    (void)other;
    return *this;
}

Intern::~Intern() {}

AForm* Intern::createShrubberyForm(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyForm(const std::string& target) {
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPardonForm(const std::string& target) {
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
    FormInfo forms[] = {
        {"shrubbery creation", &createShrubberyForm},
        {"robotomy request", &createRobotomyForm},
        {"presidential pardon", &createPardonForm}
    };
    
    const int formCount = sizeof(forms) / sizeof(forms[0]);
    
    for (int i = 0; i < formCount; i++) {
        if (formName == forms[i].name) {
            std::cout << "Intern creates " << formName << std::endl;
            return forms[i].createFunc(target);
        }
    }
    
    std::cout << "Error: Intern cannot create \"" << formName 
              << "\" form (unknown form name)" << std::endl;
    return NULL;
}