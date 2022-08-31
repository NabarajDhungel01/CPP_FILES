#include <iostream>
#include <fstream>
using namespace std;
class Haha
{
public:
    string name;
};
using namespace std;

int main()
{
    Haha ram;
    fstream fp;
    // fp.open("ok.csv");
    // while (!fp.eof())
    // {
    // fp>>ram.name;
    ram.name = "RAM,SHYAM,";
    int i =0;
    while (ram.name[i] != ',')
    {
        cout << ram.name[i];
        i++;
    }
    i = i + 1;
    cout << "\n";
    while (ram.name[i] != ',')
    {
        cout << ram.name[i];
        i++;
    }
    
    


}

// }
// fp.close();
