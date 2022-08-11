#include <iostream>
using namespace std;

class Employee
{
    private:
        int salary, age;
    public:
        int code;
        string name, level;
        void setData(string name1,string level1, int code1);
        void setData(int a1, int b1); // Declaration
        void getData(){
            cout<<"\n\nName : "<<name<<endl;
            cout<<"Code : "<<code<<endl;
            cout<<"Age : "<<age<<endl;
            cout<<"level : "<<level<<endl;
            cout<<"Salary  : "<<salary<<endl;

        }
};

void Employee :: setData(string name1,string level1, int code1) // function overloading
{
    name = name1;
    level = level1;
    code = code1;
}

void Employee :: setData(int sal1, int age1) // function overloading
{
    salary = sal1;
    age = age1;
}



int main(){
    Employee harry;
    harry.setData("HARRY","Beginner",1);
    harry.setData(1500,2);
    harry.getData();  // prints the data of harry

    // harry.salary = 1500; // it is private so cannot access from here. so to access we have to access through function
    // cout<< endl << " Salary of harry is " << harry.salary ; // it is private so cannot acces from here

    Employee ram;
    ram.setData("RAM","INTERMEDIATE",2);
    ram.setData(1600,55);
    ram.getData();
    
    Employee sita;
    sita.setData("Sita","Expert",3);
    sita.setData(2222,77);
    sita.getData();
}
