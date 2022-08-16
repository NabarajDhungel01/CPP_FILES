#include <iostream>
using namespace std;

class Person
{
private:
    int weight;

public:
    Person(int w = 0)
    {
        weight = w;
    }

    void getWeight();
    
                    // // pre increment ovcerloading // making the function
                    //         void operator ++()
                    //         {
                    //             ++weight;
                    //         }

            // post increment
            void operator ++(int)
            {
                weight++;
            }

};

int main()
{
    Person John(78);
    // post incrementing two times
    John++;
    John++;
    John.getWeight();

}   

void Person ::getWeight()
{
    cout << "\n\n Weight  " << weight << endl;
}