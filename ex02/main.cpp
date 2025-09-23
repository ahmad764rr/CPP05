#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        
        Bureaucrat alice("Alice", 1);
        Bureaucrat bob("Bob", 150);
        
        
        ShrubberyCreationForm shrub("garden");
        RobotomyRequestForm robot("target");
        PresidentialPardonForm pardon("criminal");
        
        std::cout << alice << std::endl;
        std::cout << shrub << std::endl;
        

        shrub.beSigned(alice);
        alice.executeForm(shrub);
        
        robot.beSigned(alice);
        alice.executeForm(robot);
        
        pardon.beSigned(alice);
        alice.executeForm(pardon);
        
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}