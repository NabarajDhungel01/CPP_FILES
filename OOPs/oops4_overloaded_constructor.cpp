// OVERLOADED CONSTRUCTOR

#include <iostream>
#include <string> // to include name
using namespace std;

class Person 
{
    private:
    string name;
    int age;
    float height;
    public:
                                    // Person() // non parametrized constructor
                                    // {
                                    //     name = "Null";
                                    //     age =0;
                                    //     height = 0.0f;

                                    // }

        //  INSTEAD OF WRITNG THE ABOVE NON PARAMETERIZED CONSTRUCTOR ↑↑↑
        // We will assign the default values directly down below ↓↓↓↓
    Person( string name_a = "Null", int age_a=0, float height_a = 0.0f) // Parametrized construcotr
    {
            name = name_a;
            age = age_a;
            height = height_a;
    }

    Person ( Person &obj2)  /// COPY COnstructor

    {
          name = obj2.name;
            age = obj2.age;
            height = obj2.height;
    }

    void getData ()
    {
        cout << endl<< "Name " << name;
        cout << endl << "Age " << age;
        cout << endl << "Height " << height;
    }
};

int main()
{
// lets create the new object obj3 

Person obj, obj2( "Navy",19 ,5.8), obj3( obj2);  // passing obj2 as copy
            // obj.getData(); // calling the function 

            // obj2.getData();

// obj3.getData();


obj.getData();
// here we can see we are getting the default values


}



































// // NOTES 

// #include <iostream>
// using namespace std;

// // class A
// // {
// // private:
// // int age;
// // public:
// // //-------------------------------
// // A ()                //   Non -Parameterized  Constructor
// // { age =0;}
// // //-------------------------------
// // A (int x)               //  Parameterized  Constructor
// // { age =x ;}}
// // //-------------------------------
// // A ( &obj1)                //  Copy Constructor  
// // { age = a_obj1.age}
// // //-------------------------------
// // };





// // Instead of creating separate non parameterized constructor , we will assign the value only in the parameterized constructor 
// // So the upper code becomes like this:


// class A
// {
// private:
// int age;
// public:
// //-------------------------------
// A (int x=0)   // initializing with zero instead of initializing in no parameterized constructor            //  Parameterized  Constructor
// { age =x ;}
// //-------------------------------
// A (A &a_obj1)                //  Copy Constructor  
// { age = a_obj1.age;}
// //-------------------------------
// };

// int main()
// {
// A a_obj1;
// return 0;
// }