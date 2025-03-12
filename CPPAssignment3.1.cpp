/*Q1. Write a menu driven program to calculate volume of the box(length * width * height).
Provide parameterless, parameterized(with 3 parameters) and single paramaterized constructor.
Create the local objects in respective case and call the function to caluclate area.
Menu options
-->
1. Calculate Volume with default values
2. Calculate Volume with length,breadth and height with same value
3. Calculate Volume with different length,breadth and height values.*/

#include<iostream>
using namespace std;

class Volume
{ 
    private:
    double length,width,height;

    public:
    Volume()
    {
        length=width=height=1.0;
    }

    Volume(double value)
    {
        length=width=height=value;
    }

    Volume(double l,double w,double h)
    {
        length=l;
        width=w;
        height=h;
    }

    double calculateVolume()
    {
        return length*width*height;
    }
};

int main()
{
    int choice;
    do{
    cout<<"1. Calculate Volume with default values\n";
    cout<<"2. Calculate Volume with length,breadth and height with same value\n";
    cout<<"3. Calculate Volume with different length,breadth and height values\n";
    cout<<"4. Exit\n";
    cout<<"Enter the choice:";
    cin>>choice;

    switch(choice)
    {
        case 1:{
        Volume v1;
        cout<<"Volume:"<<v1.calculateVolume()<<endl;
        break;
        }

        case 2:{
        double value;
        cout<<"Enter the length, width, height:";
        cin>>value;
        Volume v2(value);
        cout<<"Volume:"<<v2.calculateVolume()<<endl;
        break;
        }

        case 3:{
        double l,w,h;
        cout<<"Enter length, width, height:";
        cin>>l>>w>>h;
        Volume v3(l,w,h);
        cout<<"Volume:"<<v3.calculateVolume()<<endl;
        break;
        }

        case4:
        cout<<"Exiting program...\n";
        break;
        default:
        cout<<"Invalid choice!\n";
        }
    } while(choice!=4);

       
       return 0;
 }

    
