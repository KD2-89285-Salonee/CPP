/*Q2. Write a menu driven program for Date in a CPP language using structure and also using class
Date is having data members day, month, year. Implement the following functions.
void initDate();
void printDateOnConsole();
void acceptDateFromConsole();
bool isLeapYear();*/

#include <iostream>
using namespace std;

class Student {
private:
    int roll_no;
    string name; 
    int marks;

public:
    void acceptStudentFromConsole() {
        cout << "Enter the roll number: ";
        cin >> roll_no;
        cout << "Enter the name: ";
        cin >> name;
        cout << "Enter the marks: ";
        cin >> marks;
    }

    void printStudentOnConsole() {
        cout << "Roll Number: " << roll_no << endl;
        cout << "Name: " << name << endl;
        cout << "Marks: " << marks << endl;
    }
};

int menu() {
    int choice;
    cout << "\n0. Exit" << endl;
    cout << "1. Accept Student Data" << endl;
    cout << "2. Display Student Data" << endl;
    cout << "Enter the choice: ";
    cin >> choice;
    return choice; 
}

int main() {
    int choice;
    Student s;

    while ((choice = menu()) != 0) {
        switch (choice) {
            case 1:
                s.acceptStudentFromConsole();
                break;
            case 2:
                s.printStudentOnConsole();
                break;
            default:
                cout << "Wrong Choice..." << endl;
                break;
        }
    }

    cout << "Thank you for using the application!" << endl;
    return 0;
}
