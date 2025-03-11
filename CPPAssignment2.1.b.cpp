/*Q1. Write a menu driven program for Date in a CPP language using class and also using
Date is having data members day, month, year. Implement the following functions.
void initDate();
void printDateOnConsole();
void acceptDateFromConsole();
bool isLeapYear();*/
//b.Using class

#include <iostream>
using namespace std;

class Date {
private:
    int day, month;

public:
    int year;
    void initDate() {
        day = 1;
        month = 1;
        year = 2000;
    }

    void acceptDateFromConsole() {
        cout<<"Enter day: ";
        cin>>day;
        cout<<"Enter month: ";
        cin>>month;
        cout<<"Enter year: ";
        cin>>year;
    }

    void printDateOnConsole() {
        cout<<"Date: " << day << "/" << month << "/" << year << endl;
    }

    bool isLeapYear() {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }
};

int menu() {
    int choice;
    cout << "0. Exit" << endl;
    //cout << "1. Initialize Date" << endl;
    cout << "2. Accept Date from User" << endl;
    cout << "3. Display Date" << endl;
    cout << "4. Check if Leap Year" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    return choice;
}

int main() {
    int choice;
    Date d;
    d.initDate();

    while ((choice = menu()) != 0) {
        switch (choice) {
            case 1:
                d.initDate();
                break;
            case 2:
                d.acceptDateFromConsole();
                break;
            case 3:
                d.printDateOnConsole();
                break;
            case 4:
                if (d.isLeapYear())
                    cout << d.year << " is a Leap Year." << endl;
                else
                    cout << d.year << " is NOT a Leap Year." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
                break;
        }
    }

    return 0;
}
