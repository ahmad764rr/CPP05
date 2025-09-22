#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
public:
    Intern();
    Intern(const Intern& other);
    Intern& operator=(const Intern& other);
    ~Intern();

    AForm* makeForm(const std::string& formName, const std::string& target);

private:
    struct FormInfo {
        const char* name;
        AForm* (*createFunc)(const std::string& target);
    };
    
    static AForm* createShrubberyForm(const std::string& target);
    static AForm* createRobotomyForm(const std::string& target);
    static AForm* createPardonForm(const std::string& target);
};

#endif