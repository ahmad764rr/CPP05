#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat b("Alice", 150);
        b.decrementGrade();
        b.decrementGrade();
        std::cout << b << std::endl;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}
