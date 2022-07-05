#include <iostream>
using namespace std;
class Animal
{
	public:

	void sleep()
	{
		cout << "Zzzzzz";
	}

	void makeNoise()
	{
		cout << "DurrrDurrr";
	}
};
class Dog : public Animal
{
	public:

	void makeNoise()
	{
		cout << "WoofWoof";
	}
};

class Cat : public Animal
{
	public:
	
	void makeNoise()
	{
		cout << "Meaaooooow";
	}
};

int main()
{
    
    // Dog rocky;
    // rocky.makeNoise();

    Cat jerry;
    jerry.makeNoise();
    cout << endl<<endl;
    jerry.sleep();
    
}