#include <iostream>
using namespace std;


class Person
{
    private:
        int weight;
    public:
        Person(int wt = 0 )// constructor
            {
                weight = wt;
            }

    friend bool operator>(Person x, Person y);
    friend bool operator<(Person x, Person y);

};
    bool operator<(Person x, Person y)
    {
        return x.weight < y.weight;
    }

    bool operator>(Person x, Person y)
    {
        return x.weight > y.weight;
    }

int main()
{
    int w1,w2;

    cout<< "Enter the weight1(John) \t: ";
    cin >> w1;

    cout<< "Enter the weight2(Rick) \t: ";
    cin >> w2;

    Person John(w1);
    Person Rick(w2);    

if (John > Rick )
{
    cout << "John is heavy.";
}
else 
{
    cout << " Rick is heavy.";
}


return 0;
}