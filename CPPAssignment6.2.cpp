#include <iostream>
using namespace std;

class Employee
{
private:
    int id;
    double salary;

public:
    Employee()
    {
    }
    Employee(int id, double salary)
    {
        this->id = id;
        this->salary = salary;
    }
    virtual void accept()
    {
        cout << "Enter id - ";
        cin >> id;
        cout << "Enter salary - ";
        cin >> salary;
    }

    virtual void display()
    {
        cout << "Id - " << id << endl;
        cout << "Salary - " << salary << endl;
    }
};

class Manager : virtual public Employee
{
private:
    double bonus;

protected:
    void acceptManager()
    {
        cout << "Enter bonus - ";
        cin >> bonus;
    }

    void displayManager()
    {
        cout << "Bonus - " << bonus << endl;
    }

public:
    Manager()
    {
    }
    Manager(int id, double salary, double bonus) : Employee(id, salary)
    {
        this->bonus = bonus;
    }
    void setBonus(double bonus)
    {
        this->bonus = bonus;
    }

    double getBonus() const
    {
        return bonus;
    }
    void accept()
    {
        Employee::accept();
        acceptManager();
    }

    void display()
    {
        Employee::display();
        displayManager();
    }
};

class Salesman : virtual public Employee
{
private:
    double commission;

protected:
    void acceptSalesman()
    {
        cout << "Enter commission - ";
        cin >> commission;
    }

    void displaySalesman()
    {
        cout << "commission - " << commission << endl;
    }

public:
    Salesman()
    {
    }
    Salesman(int id, double salary, double commission) : Employee(id, salary)
    {
        this->commission = commission;
    }

    void setCommission(double commission)
    {
        this->commission = commission;
    }

    double getCommission() const
    {
        return commission;
    }

    void accept()
    {
        Employee::accept();
        acceptSalesman();
    }

    void display()
    {
        Employee::display();
        displaySalesman();
    }

    // void setCommission(double commission)
    // {
    //     this->commission = commission;
    // }
};

class Salesmanager : public Manager, public Salesman
{
public:
    Salesmanager()
    {
    }
    Salesmanager(int id, double salary, double bonus, double commission) : Employee(id, salary)
    {
        // use the mutators of manager and salesman to
        // add the value bonus and commission inside them
        setBonus(bonus);       
        setCommission(commission);
    }
    void accept()
    {
        // Manager::accept();
        // Salesman::accept();
        Employee::accept();
        Manager::acceptManager();
        Salesman::acceptSalesman();
    }
    void display()
    {
        Employee::display();
        Manager::displayManager();
        Salesman::displaySalesman();
    }
};

int main()
{
    Manager m;
    m.accept();
    Salesman sm;
    sm.accept();
    // Employee *eptr = new Manager();
    //  Employee *eptr = new Salesman();
    Employee *eptr = new Salesmanager();
    eptr->accept();
    eptr->display();
    delete eptr;
    return 0;
}