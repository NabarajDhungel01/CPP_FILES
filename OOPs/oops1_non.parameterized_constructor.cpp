// // STEP 1: 

// #include <iostream>
// #include <string> // to include name
// using namespace std;

// class Person 
// {
//     private:
//     string name;
//     int age;
//     float height;
//     public:
//     Person() // non parametrized constructor
//     {
//         name = "Null";
//         age =0;
//         height = 0.0f;

//     }

//     void getData ()
//     {
//         cout << endl<< "Name " << name;
//         cout << endl << "Age " << age;
//         cout << endl << "Height " << height;
//     }
// };

// int main()
// {

// Person obj;
// obj.getData(); // calling the function 
//                                         /* Lets run the program it is printing the default name age and height vbalue*/

// // here we are crearting our own constructor, but if we dont create any constrcutor the compiler will create default constructor
// // that default constructor will be used to allocate memory to these data members.

// return 0;
// }

// // STEP 2:
// // Lets remove the constructor and lets see what are the default value to be stored in the vartiable;


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
                    // deleting the constructor
                    // Person() // non parametrized constructor
                    // {
                    //     name = "Null";
                    //     age =0;
                    //     height = 0.0f;

                    // }
            // AS A RESULT WE GET THE GARBAGE VALUES WHEN WE RUN THE PROGRAM
    void getData ()
    {
        cout << endl<< "Name " << name;
        cout << endl << "Age " << age;
        cout << endl << "Height " << height;
    }
};

int main()
{

Person obj;
obj.getData(); // calling the function 
                                        /* Lets run the program it is printing the default name age and height vbalue*/

// here we are crearting our own constructor, but if we dont create any constrcutor the compiler will create default constructor
// that default constructor will be used to allocate memory to these data members.

return 0;
}
