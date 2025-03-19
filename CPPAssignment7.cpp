#include<iostream>
using namespace std;
class Employee{
                private:
                int id;
                double salary;

                public:
                Employee(){}
                Employee(int id,double salary){
                    this->id=id;
                    this->salary=salary;
                }

               virtual void accept(){
                        cout<<"Enter id:";
                        cin>>id;
                        cout<<"Enter salary:";
                        cin>>salary;
                }
                virtual void display(){
                        cout<<"ID-"<<id<<endl;
                        cout<<"Salary-"<<salary<<endl;

                }
                void setid(int id){
                    this->id=id;
                }
                int getid(){
                    return id;
                }

                void setsalary(double salary){
                    this->salary=salary;
                }
                double getsalary(){
                    return salary;
                }


};

class Manager:virtual public Employee{
private:
           double bonus;
protected:
           void acceptManager()
           {
              cout<<"Enter Bonus-";
              cin>>bonus;

           }

           void displayManager(){
            cout<<"Bonus - "<<bonus<<endl;

           }
           public:
           Manager(){}
           Manager(int id,double salary,double bonus):Employee(id, salary){
            this->bonus=bonus;
           }
           void accept(){
            Employee::accept();
            acceptManager();
           }

           void display(){
            Employee::display();
            displayManager();
           }
           void setbonus(double bonus){
            this->bonus=bonus;
        }
        double getbonus(){
               return bonus;
        }

};

class salesman:virtual public Employee{
                    private:
                    double commission;
                    protected:
                    void acceptsalesman()
                    {
                       cout<<"Enter commission-";
                       cin>>commission;
         
                    }
         
                    void displaysalesman(){
                     cout<<"commission- "<<commission<<endl;
         
                    }
                    public:
                    salesman(){}
                    salesman(int id,double salary,double commission):Employee(id,salary){
                     this->commission=commission;
                    }
                    void accept(){
                     Employee::accept();
                     acceptsalesman();
                    }
         
                    void display(){
                     Employee::display();
                     displaysalesman();
                    }

                    void setcommission(double commission){
                        this->commission=commission;
                    }
                    double getcommission(){
                            return commission;
                    }
};

class salesmanager:public Manager,public salesman
{
public:
salesmanager(){

}
salesmanager(int id,double salary,double commission,double bonus):Employee(id,salary){
                     setbonus(bonus);
                     setcommission(commission);
}

    void accept() override{
    Employee::accept();
    Manager::acceptManager();
    salesman::acceptsalesman();
  
}

    void display(){
    Employee::display();
    Manager::displayManager();
    salesman::displaysalesman();
 

}

};

int main() {
    int choice;
    int count = 0, mc = 0, sc = 0, smc = 0;
    Employee* eptr[5];

    do {
        cout << "\nMenu Options:" << endl;
        cout << "1. Add Manager" << endl;
        cout << "2. Add Salesman" << endl;
        cout << "3. Add Salesmanager" << endl;
        cout << "4. Display count of all employees" << endl;
        cout << "5. Display all Managers" << endl;
        cout << "6. Display all Salesmen" << endl;
        cout << "7. Display all Salesmanagers" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (count < 5) {
                    eptr[count] = new Manager();
                    eptr[count]->accept();
                    count++; 
                    mc++;
                } else {
                    cout << "Employee list is full!\n";
                }
                break;

            case 2:
                if (count < 5) {
                    eptr[count] = new salesman();
                    eptr[count]->accept();
                    count++;
                    sc++;
                } else {
                    cout << "Employee list is full!\n";
                }
                break;

            case 3:
                if (count < 5) {
                    eptr[count] = new salesmanager();
                    eptr[count]->accept();
                    count++;
                    smc++;
                } else {
                    cout << "Employee list is full!\n";
                }
                break;

            case 4:
                cout << "Manager count: " << mc << endl;
                cout << "Salesman count: " << sc << endl;
                cout << "SalesManager count: " << smc << endl;
                break;

            case 5:
                for (int i = 0; i < count; i++) {
                    if (typeid(*eptr[i]) == typeid(Manager)) {
                        eptr[i]->display();
                    }
                }
                break;

            case 6:
                for (int i = 0; i < count; i++) {
                    if (typeid(*eptr[i]) == typeid(salesman)) {
                        eptr[i]->display();
                    }
                }
                break;

            case 7:
                for (int i = 0; i < count; i++) {
                    if (typeid(*eptr[i]) == typeid(salesmanager)) {
                        eptr[i]->display();
                    }
                }
                break;

            case 8:
                cout << "Exiting program..." << endl;
                break;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 8);

    // Free allocated memory
    for (int i = 0; i < count; i++) {
        delete eptr[i];  
    }

    return 0;
}
