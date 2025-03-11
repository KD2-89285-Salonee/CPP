/*Q1. Write a menu driven program for Date in a CPP language using structure and also using
Date is having data members day, month, year. Implement the following functions.
void initDate();
void printDateOnConsole();
void acceptDateFromConsole();
bool isLeapYear();*/
//a.Using Stucture 

#include<iostream>
using namespace std;

struct Date {
    int day, month, year;

    void initDate()
        {
            day=1;
            month=1;
            year=2000;
        }
    void acceptDateFromConsole()
    {
        cout<<"Enter day:";
        cin>>day;
        cout<<"Enter month:";
        cin>>month;
        cout<<"Enter year:";
        cin>>year;
    }
    void printDateOnConsole()
    {
        cout<<"Date:"<<day<<"-"<<month<<"-"<<year<<endl;
    }
    bool isLeapYear()
    {
        if((year%4==0 && year%100==0) || (year%400==0))
        return true;
        else
        return false;
    }
};
int menu()
{
    int choice;
    cout<<"0. Exit"<<endl;
    // cout<<"1.Initialize Date" << endl;
    cout<<"2. Accept date from user" << endl;
    cout<<"3. Display date" << endl;
    cout<<"4. Check if leap year" << endl;
    cout<<"Enter your choice: ";
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
                cout << "Date initialized to default (01/01/2000)" << endl;
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

    cout << "Thank you for using the application!" << endl;
    return 0;
}