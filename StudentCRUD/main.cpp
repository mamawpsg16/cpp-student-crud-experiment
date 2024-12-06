#include "Student.h"
#include <iostream>
#include <limits>
#include <string>
#include <cctype> // For isalpha and isspace functions
#include <vector>
#include "Log.h"
using std::cout;
using std::cin;

#define OUTPUT(text) cout << text;

int role;
std::string firstName;
std::string middleName;
std::string lastName;
std::string save;
int id = 0;
int age;
int gradeSchool;

std::vector<Student> students; // Vector to store multiple Student objects

bool isStringInputValid(const std::string& input) {
	// Check for invalid characters
	bool valid = true;
	for (char c : input) {
		if (!std::isalpha(c) && !std::isspace(c)) {
			valid = false;
			break;
		}
	}

	return valid;
}
void studentInput() {
	while (true)
	{
		OUTPUT("Enter first name: "); // Output prompt for user input
		// Continuously prompt until valid input
		while (true) {
			std::getline(std::cin, firstName); // Read input from user

			// Check if the input is empty
			if (firstName.empty()) {
				OUTPUT("\nInvalid input.\n")
					OUTPUT("Enter first name:")
					continue; // Prompt again if empty
			}

			// Check for invalid characters (only letters and spaces allowed)
			bool isValid = isStringInputValid(firstName);
			if (!isValid) {
				std::cout << "\nInvalid input, please enter a valid first name (letters and spaces only).\n";
				OUTPUT("Enter first name: ")
					continue; // Prompt again if invalid characters are found
			}

			break; // Exit the loop if valid input is given
		}

		OUTPUT("Enter middle name: "); // Output prompt for user input
		// Continuously prompt until valid input
		while (true) {
			std::getline(std::cin, middleName); // Read input from user

			// Check if the input is empty
			if (middleName.empty()) {
				OUTPUT("\nInvalid input.\n")
					OUTPUT("Enter middle name:")
					continue; // Prompt again if empty
			}

			// Check for invalid characters (only letters and spaces allowed)
			bool isValid = isStringInputValid(middleName);
			if (!isValid) {
				std::cout << "\nInvalid input, please enter a valid middle name (letters).\n";
				OUTPUT("Enter middle name: ")
					continue; // Prompt again if invalid characters are found
			}

			break; // Exit the loop if valid input is given
		}

		OUTPUT("Enter last name: "); // Output prompt for user input
		// Continuously prompt until valid input
		while (true) {
			std::getline(std::cin, lastName); // Read input from user

			// Check if the input is empty
			if (lastName.empty()) {
				OUTPUT("\nInvalid input.\n")
					OUTPUT("Enter last name:")
					continue; // Prompt again if empty
			}

			// Check for invalid characters (only letters and spaces allowed)
			bool isValid = isStringInputValid(lastName);
			if (!isValid) {
				OUTPUT("\nInvalid input, please enter a valid last name (letters and spaces only).\n");
				OUTPUT("Enter last name: ")
					continue; // Prompt again if invalid characters are found
			}

			break; // Exit the loop if valid input is given
		}
		OUTPUT("Verify details, before saving. \n\n")
			OUTPUT("\nStudent Details:\n")
			OUTPUT("\t First Name: " << firstName << "\n");
		OUTPUT("\t Middle Name: " << middleName << "\n");
		OUTPUT("\t Last Name: " << lastName << "\n\n");

		do {
			OUTPUT("Are you sure you want to save these details? yes(y) or no(n): ");
			std::getline(std::cin, save);

			if (save.empty()) {
				OUTPUT("\nInvalid input.\n\n");
				continue;
			}

			if (!isStringInputValid(save) || (save != "y" && save != "n")) {
				OUTPUT("\nInvalid input. Please enter 'y' or 'n'.\n\n");
				continue; // Prompt again if invalid characters are found
			}

		} while (save != "y"); // Corrected condition

		if (save == "y") {
			// Create a Student object with the gathered information
			Student newStudent(++id, firstName, middleName, lastName);
			students.push_back(newStudent);
			OUTPUT("Details saved successfully.\n");
			break;
		}
		else {
			OUTPUT("Details not saved.\n");
		}
	}
}

void chooseProgram() {
	OUTPUT("Welcome to school simulation, please choose a role you want to enact: \n");
	OUTPUT("Roles:");
	OUTPUT("\t 1 - Student \n");
	OUTPUT("\t 2 - Teacher (username = user, password = password) \n\n");
}


int main() {
	Log("LOGGGG");
	chooseProgram();

	OUTPUT("Enter your chosen role to enact: ")

		while (!(cin >> role) || role > 2 || role <= 0) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			OUTPUT("\nInvalid role, choose between (1 = Student, 2 = Teacher).\n");
			OUTPUT("\nEnter your chosen role to enact: ")
		}

	// Clear the leftover newline character after role input
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	if (role == 1) {
		OUTPUT("You are now renacting as student. \n\n")
			studentInput();
	}

	return 0;
}