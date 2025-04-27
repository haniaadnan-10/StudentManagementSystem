#include <iostream>
#include <string>
#include <vector>
using namespace std;

void displayMenu() {
	cout << "Welcome to Student Management System." << endl;
	cout << "1. Add Student." << endl;
	cout << "2. View Student." << endl;
	cout << "3. Uptade Student." << endl;
	cout << "4. Delete Student." << endl;
	cout << "5. Exit." << endl;
}

void addStudent(vector<string>& students) {
	string name;
	cout << "Enter the name of student: " << "\n";
	cin.ignore();
	getline(cin, name);
	students.push_back(name);
	cout << "Student Added Successfully." << "\n";
}

void viewStudent(const vector<string>& students) {
	if (students.empty()) {
		cout << "No student to show." << "\n";
	}
	else {
		for (int i = 0; i < students.size(); i++) {
			cout << i << ":" << students[i] << " ";
		}
		cout << endl;
	}
}

void uptadeStudent(vector<string>& students) {
	int index;
	string newName;
	cout << "Enter the index of the student name you want to uptade: ";
	cin >> index;

	if (index >= 0 && index <= students.size()) {
		cout << "Enter the new Name: " << endl;
		cin >> newName;
		students[index] = newName;
		cout << "Student Name uptaded succesfully." << endl;
	}
	else {
		cout << "Invalid index number.";
	}

}

void deleteStudent(vector<string>& students) {
	int index;
	cout << "Enter the index of the student you want to delete: ";
	cin >> index;

	if (index >= 0 && index < students.size()) {
		students.erase(students.begin() + index);
		cout << "Student deleted succesfully." << endl;
	}
	else {
		cout << "Invalid index." << endl;
	}
}

int main() {
	int choice;
	char ans;
	vector<string> students;
	do {
		displayMenu();
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			do {
				addStudent(students);
				cout << "Do you want to add another student?" << "\n";
				cin >> ans;
				cin.ignore();
			} while (ans == 'Y' || ans == 'y');
			break;
		case 2:
			viewStudent(students);
			break;
		case 3:
			do {
				uptadeStudent(students);
				cout << "Do you want to uptade another student name?" << "\n";
				cin >> ans;
				cin.ignore();
			} while (ans == 'Y' || ans == 'y');
			break;
		case 4:
			do {
				deleteStudent(students);
				cout << "Do you want to delete another student?" << "\n";
				cin >> ans;
				cin.ignore();
			} while (ans == 'Y' || ans == 'y');
			break;
		case 5:
			cout << "Exiting the program.";
			break;
		default:
			cout << "Invalid choice number.";
		}
	} while (choice != 5);

	return 0;
}