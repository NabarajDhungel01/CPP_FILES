// PARAMETERIZED CONSTRUCTOR

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

    void getData ()
    {
        cout << endl<< "Name " << name;
        cout << endl << "Age " << age;
        cout << endl << "Height " << height;
    }
};

int main()
{
// lets create the new object obj2
Person obj, obj2( "Navy",19 ,5.8);
obj.getData(); // calling the function 
                                    
obj2.getData();

return 0;
}