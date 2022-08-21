#include <iostream>
using namespace std;
class Person
{
private:
int weight;
public:
Person(int wt =0 )
{
    weight = wt;
}
void getweight()
{
    cout <<endl << "Weight is  : "<<weight ;
}
friend class Boy;     // friend class
friend class Girl;     // friend class
friend int Addweight(Boy b1, Girl g1); // friend function


};
class Boy: public Person
{
private:

public:
Boy(int wt =0)
{
    weight = wt;
}
friend int Addweight(Boy b1, Girl g1); // friend function

};


class Girl: public Person
{
private:

public:
Girl(int wt =0)
{
    weight = wt;
}
friend int Addweight(Boy b1, Girl g1); // friend function

};

int  Addweight(Boy b1,Girl g1)
{
    return b1.weight+g1.weight;
}

int main()
{
    Boy Ram(70);
    Ram.getweight();
    Girl Sita(50);
    Sita.getweight();



return 0;
}