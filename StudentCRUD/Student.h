// Student.h
#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student {
private:
    int id;
    std::string firstName;
    std::string middleName;
    std::string lastName;

public:
    // Constructor to initialize the student details
    Student(int id, std::string& firstName, std::string& middleName, std::string& lastName)
        : id(id), firstName(firstName), middleName(middleName), lastName(lastName) {}

    // Getter methods to access the student details
    int getId() const { return id; }
    std::string getFirstName() const { return firstName; }
    std::string getMiddleName() const { return middleName; }
    std::string getLastName() const { return lastName; }
};

#endif // STUDENT_H
