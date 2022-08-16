
// OPERATOR OVERLOADING
// WAP TO add the weight using the operator overloading method

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
    // REMOVING THE ADD WEIGHT FUNCTION FOR THE OPERATOR OVERLOADING
    // A addWeight(A w2)
    // {
    //     A temp;
    //     temp.weight = weight + w2.weight;
    //     return temp;
    // }
    // ADDING THE NEW FUNCTION FOR THE OPERATOR OVERLOADING

    // function overloading is similiar to the traditional fucntion overloading 

    A operator + (A w2)
    {
        A temp;
        temp.weight = weight + w2.weight ;
        return temp;
    }

    void getweight();
};

int main()
{
    int a = 63, b = 74, c = 0;
    c = a + b;

    A person1(63);
    A person2(74);
    A total;

    total = person1 + person2;

    total.getweight();
}

void A ::getweight()
{
    cout << "Weight " << weight;
}