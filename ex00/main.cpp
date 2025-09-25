#include "Bureaucrat.hpp"

int main() {
    std::cout << "=== Testing Bureaucrat Creation ===" << std::endl;
    
    // Valid bureaucrats
    try {
        Bureaucrat alice("Alice", 1);
        std::cout << alice << std::endl;
        
        Bureaucrat bob("Bob", 150);
        std::cout << bob << std::endl;
        
        Bureaucrat charlie("Charlie", 75);
        std::cout << charlie << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n=== Testing Grade Too High Exception ===" << std::endl;
    try {
        Bureaucrat invalid("TooHigh", 0);
    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Testing Grade Too Low Exception ===" << std::endl;
    try {
        Bureaucrat invalid("TooLow", 151);
    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Testing Grade Increment/Decrement ===" << std::endl;
    try {
        Bureaucrat dave("Dave", 2);
        std::cout << "Before increment: " << dave << std::endl;
        dave.incrementGrade();
        std::cout << "After increment: " << dave << std::endl;
        
        // This should throw an exception
        dave.incrementGrade();
    } catch (const std::exception& e) {
        std::cerr << "Caught exception during increment: " << e.what() << std::endl;
    }

    try {
        Bureaucrat eve("Eve", 149);
        std::cout << "Before decrement: " << eve << std::endl;
        eve.decrementGrade();
        std::cout << "After decrement: " << eve << std::endl;
        
        // This should throw an exception
        eve.decrementGrade();
    } catch (const std::exception& e) {
        std::cerr << "Caught exception during decrement: " << e.what() << std::endl;
    }

    std::cout << "\n=== Testing Copy Constructor and Assignment ===" << std::endl;
    try {
        Bureaucrat original("Original", 42);
        Bureaucrat copy(original);
        Bureaucrat assigned("Temp", 100);
        
        std::cout << "Original: " << original << std::endl;
        std::cout << "Copy: " << copy << std::endl;
        
        assigned = original;
        std::cout << "Assigned: " << assigned << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
