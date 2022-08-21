#include <iostream>
using namespace std;
class Alpha
{
private:
int a1;
public:
Alpha(int arg =0)
{
    a1 =arg;
}
friend class Beta;
};

class Beta
{
private:
int b1;
public:
Beta(int arg =0)
{
    b1 =arg;
}
;
int  sum()
{
    Alpha alpha_obj(1);
    int sum= alpha_obj.a1+b1;   //here beta is inaccessible if the class Beta is not declared as a friend in the class Alpha
    return sum;
}
};

int main()
{
Beta beta_obj(7);

beta_obj.sum();


return 0;
}


// Here we dont have to interact with the various class in the main itself


// TAKEAWAY: Now all  member functions of beta can access private data of Alpha