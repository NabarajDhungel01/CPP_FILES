// TRADUTIONAL ADDING THE VARIABLES OF OBJECTS
// OPERATOR OVERLOADING
// WAP TO add the weight using the traditional method

#include <iostream>
using namespace std;

class A
{
private:
    int weight;

public:
    A(int x = 0)
    {
        weight = x;
    }
    A addWeight(A w2)
    {
        A temp;
        temp.weight = weight + w2.weight;
        return temp;
    }
    void getweight()
    {
        cout << "Weight " << weight;
    }
};

int main()
{
    int a = 63, b = 74, c = 0;
    c = a + b;
    /* here the c = a+b is the operation between the pre defined data types. but when we want to add the user defined data types
     it loses is capability

     We have two approach to add the two objects
     1. Traditional Approach
        -►in traditinal approach we create an addweight function to add
     2. Operator Overloading Approach
        -► In this menthod we do the operator overtloading

    */

    A person1(63);
    A person2(74);
    A total;
    total = person1.addWeight(person2); // either this or this ↓↓↓↓
    // total = person2.addWeight(person1);
    total.getweight();
}