#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat b("Alice", 42);
        std::cout << b << std::endl;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}
