#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
    try {
        // Create bureaucrats
        Bureaucrat alice("Alice", 1);
        Bureaucrat bob("Bob", 150);
        
        // Create an intern
        Intern someRandomIntern;
        
        std::cout << "=== Testing Intern Form Creation ===" << std::endl;
        
        // Test creating different forms
        AForm* rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        AForm* scf = someRandomIntern.makeForm("shrubbery creation", "garden");
        AForm* ppf = someRandomIntern.makeForm("presidential pardon", "criminal");
        AForm* invalid = someRandomIntern.makeForm("unknown form", "target");
        
        std::cout << "\n=== Testing Form Execution ===" << std::endl;
        
        if (rrf) {
            std::cout << *rrf << std::endl;
            rrf->beSigned(alice);
            alice.executeForm(*rrf);
            delete rrf;
        }
        
        if (scf) {
            std::cout << *scf << std::endl;
            scf->beSigned(alice);
            alice.executeForm(*scf);
            delete scf;
        }
        
        if (ppf) {
            std::cout << *ppf << std::endl;
            ppf->beSigned(alice);
            alice.executeForm(*ppf);
            delete ppf;
        }
        
        if (invalid) {
            delete invalid; // Should not happen, but safety check
        }
        
        std::cout << "\n=== Testing with Low Grade Bureaucrat ===" << std::endl;
        AForm* testForm = someRandomIntern.makeForm("robotomy request", "TestTarget");
        if (testForm) {
            try {
                testForm->beSigned(bob); // This should fail
            } catch (std::exception& e) {
                std::cout << "Bob couldn't sign: " << e.what() << std::endl;
            }
            delete testForm;
        }
        
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    
    return 0;
}