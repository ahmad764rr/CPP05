#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat b("Alice", 50);
        Form f("Top Secret Form", 40, 20);

        std::cout << f << std::endl;
        b.signForm(f);

        std::cout << f << std::endl;

    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}
