#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    std::cout << "=== Testing Concrete Forms Creation ===" << std::endl;
    try {
        ShrubberyCreationForm shrub("garden");
        RobotomyRequestForm robot("Bender");
        PresidentialPardonForm pardon("Arthur_Dent");
        
        std::cout << shrub << std::endl;
        std::cout << robot << std::endl;
        std::cout << pardon << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n=== Testing Form Signing and Execution - Success ===" << std::endl;
    try {
        Bureaucrat president("President", 1);
        ShrubberyCreationForm shrub("home");
        
        std::cout << "Before signing: " << shrub << std::endl;
        president.signForm(shrub);
        std::cout << "After signing: " << shrub << std::endl;
        president.executeForm(shrub);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n=== Testing RobotomyRequestForm ===" << std::endl;
    try {
        Bureaucrat engineer("Engineer", 30);
        RobotomyRequestForm robot("Target");
        
        engineer.signForm(robot);
        engineer.executeForm(robot);
        engineer.executeForm(robot);  // Try again to see randomness
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n=== Testing PresidentialPardonForm ===" << std::endl;
    try {
        Bureaucrat president("President", 1);
        PresidentialPardonForm pardon("Ford_Prefect");
        
        president.signForm(pardon);
        president.executeForm(pardon);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n=== Testing Execution Without Signing ===" << std::endl;
    try {
        Bureaucrat lowBureaucrat("LowLevel", 140);
        ShrubberyCreationForm unsignedForm("test");
        
        lowBureaucrat.executeForm(unsignedForm);  // Should fail - not signed
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n=== Testing Insufficient Grade for Signing ===" << std::endl;
    try {
        Bureaucrat lowBureaucrat("LowLevel", 100);
        PresidentialPardonForm secretForm("Criminal");
        
        lowBureaucrat.signForm(secretForm);  // Should fail - grade too low
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n=== Testing Insufficient Grade for Execution ===" << std::endl;
    try {
        Bureaucrat president("President", 1);
        Bureaucrat intern("Intern", 100);
        PresidentialPardonForm pardon("Someone");
        
        president.signForm(pardon);
        intern.executeForm(pardon);  // Should fail - grade too low for execution
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}