/*Q2. Imagine a tollbooth at a bridge. Cars passing by the booth are expected to pay a fifty-cent toll.
Mostly they do, but sometimes a car goes by without paying.
The tollbooth keeps track of the number of cars that have gone by and of the total amount of money collected.
Model this tollbooth with a class called tollbooth.
The two data items are a type unsigned int to hold the total number of cars, and a type double to hold the total amount of money collected
A constructor initializes all data members to 0. A member function called payingCar() increments
the car total and adds 0.50 to the cash total. An other function, called nopayCar()
increments the car total but adds nothing to the cash total. Finally, a member function called
printOnConsole() displays the two totals and number of paying as well as non paying cars total.*/

#include <iostream>
using namespace std;

class TollBooth {
private:
    unsigned int totalCars;
    unsigned int payingCars;
    unsigned int nonPayingCars;
    double totalAmount;

public:
    
    TollBooth() {
        totalCars = 0;
        payingCars = 0;
        nonPayingCars = 0;
        totalAmount = 0.0;
    }

   
    void payingCar() {
        totalCars++;
        payingCars++;
        totalAmount += 0.50;
    }

    
    void nopayCar() {
        totalCars++;
        nonPayingCars++;
    }

    
    void printOnConsole() {
        cout << "\nTotal cars passed: " << totalCars << endl;
        cout << "Paying cars: " << payingCars << endl;
        cout << "Non-paying cars: " << nonPayingCars << endl;
        cout << "Total money collected: $" << totalAmount << endl;
    }
};

int main() {
    TollBooth booth;
    int choice;

    do {
        cout << "1. Record a paying car\n";
        cout << "2. Record a non-paying car\n";
        cout << "3. Display tollbooth statistics\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                booth.payingCar();
                cout << "Paying car recorded!\n";
                break;
            case 2:
                booth.nopayCar();
                cout << "Non-paying car recorded!\n";
                break;
            case 3:
                booth.printOnConsole();
                break;
            case 4:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
