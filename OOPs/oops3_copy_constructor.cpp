// COPY CONSTRUCTOR

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
    Person() // non parametrized constructor
    {
        name = "Null";
        age =0;
        height = 0.0f;

    }

    Person( string name_a, int age_a, float height_a) // Parametrized construcotr
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

obj3.getData();

// we can see the same value as obj 2

}