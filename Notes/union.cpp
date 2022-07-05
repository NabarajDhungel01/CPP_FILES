//UNIon NOTES BY CODEWITH HARRY


#include <iostream>
using namespace std;

typedef struct emp
{
char name[20];    //4 bytes
int age;    //1 bytes
int code;    //4 bytes
}STEMP;

// FOR STRUCT 9 BYTES IS USING


// OUT OF THE THREEE THINGS BELOW, WE CAN ONLY USE ONLY ONE THING AT A TIME.
// if i m using car i cant set rice and pound


// WHAT CPP SAYS IS If user wants to use only one thing at a time from this union, CPP will create a shared memory for all
union money
{   
    /*data*/
    int rice;     //4 bytes
    char car;      //1 bytes
    float dollars;     //4 bytes
};
// FOR STRUCT 4 BYTES WILL BE ALLOCATED BCZ ONLY ONE THING IS GOING TO BE USED 



int main()
{

    union money m1;
    m1.rice = 34;
    cout << m1.rice << endl ;
    
    // IF i used any other thing from the union, then this will be overwritten
     m1.car = 'C';
    cout << m1.rice << endl ; // i am using another thing to store diff thing in m1.car but this will overwrite rice so hence error and 
    // UNION ARE BETTER FOR MEMORY MANAGEMENT

    // here rice value will be garbage and
    // i can only get the good value of car
    
    cout << m1.car;



return 0;
}