#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class AForm {
private:
    const std::string name;
    bool isSigned;
    const int signGrade;
    const int execGrade;

public:
    AForm();
    AForm(const std::string& n, int sGrade, int eGrade);
    virtual ~AForm();
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);

    const std::string& getName() const;
    bool getIsSigned() const;
    int getSignGrade() const;
    int getExecGrade() const;

    void beSigned(const Bureaucrat& b);
    virtual void execute(Bureaucrat const& executor) const = 0;

    class GradeTooHighException : public std::exception {
        const char* what() const throw();
    };
    class GradeTooLowException : public std::exception {
        const char* what() const throw();
    };
    class NotSignedException : public std::exception {
        const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif