/*Q1. Create a class Date with data memebrs day,month and year.
Create a class Person with data members name,address and birthdate. The birthdate should be of type Date.
Create a class Student with data members id, marks , course and joining date , end date . The joining
date and end date should be of type date. Implement above classes. Test all functionalities in main().
(Note- Only Perform the Association in the above case. No need of Inheritance)*/

#include <iostream>
#include <string>
using namespace std;

class Date {
private:
    int day, month, year;
public:
    Date() : day(0), month(0), year(0) {
        cout << "Date()" << endl;
    }
    Date(int d, int m, int y) : day(d), month(m), year(y) {
        cout << "Date(int, int, int)" << endl;
    }
    void acceptDate() {
        cout << "Enter day: ";
        cin >> day;
        cout << "Enter month: ";
        cin >> month;
        cout << "Enter year: ";
        cin >> year;
    }
    void displayDate() const {
        cout << day << "/" << month << "/" << year;
    }
};

class Person {
private:
    string name, address;
    Date birthdate; // Association
public:
    Person() {
        cout << "Person()" << endl;
    }
    Person(string n, string addr, int d, int m, int y) : name(n), address(addr), birthdate(d, m, y) {
        cout << "Person(string, string, Date)" << endl;
    }
    void acceptPerson() {
        cin.ignore(); // Handle previous input
        cout << "Enter name: ";
        getline(cin, name);
        cout << "Enter address: ";
        getline(cin, address);
        cout << "Enter birthdate " << endl;
        birthdate.acceptDate();
    }
    void displayPerson() const {
        cout << "Name: " << name << "\nAddress: " << address << "\nBirthdate: ";
        birthdate.displayDate();
        cout << endl;
    }
};

class Student {
private:
    int id;
    float marks;
    string course;
    Date *joiningDate;
    Date *endDate; // Aggregation
public:
    Student() : joiningDate(nullptr), endDate(nullptr) {
        cout << "Student()" << endl;
    }
    Student(int i, float m, string c, int jd, int jm, int jy, int ed, int em, int ey)
        : id(i), marks(m), course(c) {
        joiningDate = new Date(jd, jm, jy);
        endDate = new Date(ed, em, ey);
        cout << "Student(int, float, string, Date, Date)" << endl;
    }
    void acceptStudent() {
        cout << "Enter Student ID: ";
        cin >> id;
        cout << "Enter Marks: ";
        cin >> marks;
        cin.ignore();
        cout << "Enter Course: ";
        getline(cin, course);
        joiningDate = new Date();
        endDate = new Date();
        cout << "Enter Joining Date " << endl;
        joiningDate->acceptDate();
        cout << "Enter End Date: " << endl;
        endDate->acceptDate();
    }
    void displayStudent() const {
        cout << "Student ID: " << id << "\nMarks: " << marks << "\nCourse: " << course;
        cout << "\nJoining Date: ";
        joiningDate->displayDate();
        cout << "\nEnd Date: ";
        endDate->displayDate();
        cout << endl;
    }
    ~Student() {
        delete joiningDate;
        delete endDate;
    }
};

int main() {
    // Testing Person class
    Person p1;
    p1.acceptPerson();
    p1.displayPerson();
    
    // Testing Student class
    Student s1;
    s1.acceptStudent();
    s1.displayStudent();
    
    return 0;
}


/*http://192.168.50.99/exam*/
