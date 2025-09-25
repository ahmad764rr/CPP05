#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    std::cout << "=== Testing Form Creation ===" << std::endl;
    try {
        Form form1("Tax Form", 50, 25);
        Form form2("Top Secret", 1, 1);
        Form form3("Basic Form", 150, 150);
        
        std::cout << form1 << std::endl;
        std::cout << form2 << std::endl;
        std::cout << form3 << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error creating forms: " << e.what() << std::endl;
    }

    std::cout << "\n=== Testing Form Exception: Grade Too High ===" << std::endl;
    try {
        Form invalidForm("Invalid", 0, 50);
    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Testing Form Exception: Grade Too Low ===" << std::endl;
    try {
        Form invalidForm("Invalid", 50, 151);
    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Testing Form Signing - Success ===" << std::endl;
    try {
        Bureaucrat alice("Alice", 30);
        Form form("Contract", 50, 25);
        
        std::cout << "Before signing: " << form << std::endl;
        alice.signForm(form);
        std::cout << "After signing: " << form << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n=== Testing Form Signing - Failure (Grade Too Low) ===" << std::endl;
    try {
        Bureaucrat bob("Bob", 100);
        Form secretForm("Top Secret", 50, 25);
        
        std::cout << "Before signing attempt: " << secretForm << std::endl;
        bob.signForm(secretForm);
        std::cout << "After signing attempt: " << secretForm << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n=== Testing beSigned() directly ===" << std::endl;
    try {
        Bureaucrat charlie("Charlie", 10);
        Form form("Direct Test", 20, 15);
        
        std::cout << "Before beSigned: " << form << std::endl;
        form.beSigned(charlie);
        std::cout << "After beSigned: " << form << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error in beSigned: " << e.what() << std::endl;
    }

    std::cout << "\n=== Testing beSigned() failure ===" << std::endl;
    try {
        Bureaucrat dave("Dave", 75);
        Form restrictedForm("Restricted", 50, 25);
        
        std::cout << "Before beSigned: " << restrictedForm << std::endl;
        restrictedForm.beSigned(dave);  // Should throw exception
        std::cout << "After beSigned: " << restrictedForm << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error in beSigned: " << e.what() << std::endl;
    }

    return 0;
}
