/*Q3.Create a namespace NStudent. Create the Student class(created as per assignment 1 Q3) inside
namespace. Create the obje ct of student and perform accept and display student.*/

#include <iostream>
using namespace std;

// Creating namespace NStudent
namespace NStudent {
    class Student {
    private:
        string name;
        int rollNo;
        float marks;

    public:
        // Function to accept student details
        void acceptStudent() {
            cout << "Enter Student Name: ";
            cin.ignore(); // Ignore previous newline character
            getline(cin, name);
            cout << "Enter Roll Number: ";
            cin >> rollNo;
            cout << "Enter Marks: ";
            cin >> marks;
        }

        // Function to display student details
        void displayStudent() {
            cout << "\nStudent Details:\n";
            cout << "Name: " << name << endl;
            cout << "Roll Number: " << rollNo << endl;
            cout << "Marks: " << marks << endl;
        }
    };
}

int main() 
{
    NStudent::Student s1;
    s1.acceptStudent();
    s1.displayStudent();
    return 0;
}
