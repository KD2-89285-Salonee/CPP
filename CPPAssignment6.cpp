/*Q1. A shop sells book or tapes. The Book class holds id, title, author, and price; whereas Tape class
holds id, title, artist, and price. There is 5% discount on tapes, while 10% discount on books.
Assuming that each user purchase 3 products (either book or tape), calculate final bill. The program
should be menu driven and should not cause memory leakage.
Hint-Create class Product and inherit into Book and Tape. Also create array like Product* arr[3]*/

#include<iostream>
using namespace std;
class Product
{
    protected:
    int id;
    string title;
    float price;

    public:
    virtual void acceptdata()=0;
    virtual void displaydata()const =0;
    virtual float calculatediscount()const=0;
    virtual ~Product(){}
};
class Book : public Product
{    
    // private:
    // int id;
    // string title;
    string author;
    // int price;

    public:
    void acceptdata()override
    {
        cout<<"Enter the book id:"<<endl;
        cin>>id;
        cin.ignore();
        cout<<"Enter the book title:"<<endl;
        getline(cin,title);
        // cin>>title;
        cout<<"Enter the book author:"<<endl;
        getline(cin,author);
        // cin>>author;
        cout<<"Enter the book price:"<<endl;
        cin>>price;
        
    }
    void displaydata()const override
    {
        
        cout<<"Book ID:"<<" "<<id<<"Title:"<<" "<<title<<"Author:"<<" "<<author<<"Price:"<<" "<<price<< ", Discounted Price: " << calculatediscount() << endl;
    }
    float calculatediscount() const override
    {
        return price*0.90;
    }
};

class Tape : public Product 
{
    private:
    // int id;
    // string title;
    string artist;
    // int price;

    public:
    void acceptdata()override
    {
        cout<<"\nEnter the book id:"<<endl;
        cin>>id;
        cin.ignore();
        cout<<"Enter the tape title:"<<endl;
        getline(cin,title);
        // cin>>title;
        cout<<"Enter the tape artist:"<<endl;
        getline(cin,artist);
        // cin>>artist;
        cout<<"Enter the tape price:"<<endl;
        cin>>price;

    }
    void displaydata()const override
    {
        
        cout << "Tape ID: " << id << ", Title: " << title << ", Artist: " << artist 
             << ", Price: " << price << ", Discounted Price: " << calculatediscount() << endl;
    }

    float calculatediscount() const override
    {
        return price*0.95;
    }
};
    
    // int menu()
    // {
    //     int choice;
    //     cout<<"0.Exit"<<endl;
    //     cout<<"1.Select product type for item"<<endl;
    //     cout<<"2.Display discounted price"<<endl;
    //     cout<<"3";
    // }

    int main()
    {
        Product *arr[3];
        double totalbill=0;

        for (int i=0; i<3; i++)
        {
            int choice;
            cout<<"\nSelect product type for item"<<i+1<<":";
            cout << "\n1. Book";
            cout << "\n2. Tape";
            cout << "\nEnter choice: ";
            cin >> choice;
    
            if (choice == 1) {
                arr[i] = new Book();
            } else if (choice == 2) {
                arr[i] = new Tape();
            } else {
                cout << "Invalid choice! Please enter 1 or 2.\n";
                i--;  // Retry input for this index
                continue;
            }
    
            arr[i]->acceptdata();
        }
    
        cout << "\nPurchased Items:\n";
        for (int i = 0; i < 3; i++) {
            arr[i]->displaydata();
            totalbill += arr[i]->calculatediscount();
        }
    
        cout << "\nTotal Bill after discount: " << totalbill << endl;
    
        // Free allocated memory
        for (int i = 0; i < 3; i++) {
            delete arr[i];
        }
    
        return 0;
    }