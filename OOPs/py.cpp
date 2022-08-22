#include <iostream>
using namespace std;

int main()
{
    char nabaraj123[]= {'n','a','b','a','r','a','j','1','2','3'};
    
    char Nabaraj[]= {'N','a','b','a','r','a','j'};
    char sudarshan[9] = {'s','u','d','a','r','s','h','a','n'};
    char sudarshan789[12] = {'s','u','d','a','r','s','h','a','n','7','8','9'};


    for (int i = 0; i <12; i++)
    {
        cout << "keyboard.press('" <<sudarshan789[i]<<"')"<<endl;
        cout << "keyboard.release('" <<sudarshan789[i]<<"')"<<endl;
        cout << endl;
    }
    


return 0;
}