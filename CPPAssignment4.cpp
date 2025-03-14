#include <iostream>
using namespace std;

class Time {
private:
    int hour, minute, seconds;

public:
    Time() {
        hour = 0;
        minute = 0;
        seconds = 0;
    }

    Time(int hour, int minute, int seconds) {
        this->hour = hour;
        this->minute = minute;
        this->seconds = seconds;
    }

    void accept() {
        cout << "Enter the hour: ";
        cin >> hour;
        cout << "Enter the minutes: ";
        cin >> minute;
        cout << "Enter the seconds: ";
        cin >> seconds;
    }

    void setHour(int h) {
        this->hour = h;
    }

    void setMinute(int m) {
        this->minute = m;
    }

    void setSeconds(int s) {
        this->seconds = s;
    }

    void printTime() {
        cout << "Time: " << hour << ":" << minute << ":" << seconds << endl;
    }

    int getHour() {
        return hour;
    }

    int getMinutes() {
        return minute;
    }

    int getSeconds() {
        return seconds;
    }
};

int menu() {
    int choice;
    cout << "\n1. Add Time" << endl;
    cout << "2. Display Time" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    return choice;
}

int main() {
    int n;
    cout << "Enter the number of time objects: ";
    cin >> n;

    // Allocate memory dynamically for an array of Time pointers
    Time**ptr = new Time*[n];

    int choice;
    while ((choice = menu()) != 3) {  // Loop until the user chooses to exit
        switch (choice) {
            case 1:
                for (int i = 0; i < n; i++) {
                    ptr[i] = new Time(); // Allocate memory for each object
                    ptr[i]->accept();
                }
                break;

            case 2:
                for (int i = 0; i < n; i++) {
                    ptr[i]->printTime();
                }
                break;

            default:
                cout << "Invalid choice, please try again!" << endl;
                break;
        }
    }
    for (int i = 0; i < n; i++) {
        delete ptr[i];  
    }
    delete[] ptr;  
    ptr = NULL;
    

    return 0;
}
