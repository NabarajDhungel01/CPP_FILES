//Program to return the number of the input position

#include <iostream>
#include <math.h>
using namespace std;
int rev_num(int num,int *c, int *rev);
int tot_char(int num,int *c);

int main()
{

int count = 0;
int *ptr_count;
ptr_count = &count;

int rev = 0 ;
int *ptr_rev;
ptr_rev = &rev;



int num = 123456789;

tot_char(num,ptr_count);
rev_num(num,  ptr_count, ptr_rev);
return 0;


}
int tot_char(int num,int *c)
{
    int count = 0 ;
    while (num !='\0')
    {
     count = count +1;
     num = num/10;

    }
    cout <<endl << "Count is : "<< count ;
    *c = count;

}

int rev_num(int num,int *c,int *reverse)
{

int a;
int rem;
for (int i = 0; i < *c ; i++)

{
    rem = num % 10;
    (*reverse) = (( *reverse)*10 )+ rem;
    num = num /10;
}

cout << endl << "Rev is  : " << *(reverse);

}



int n_number(int number_num,int pos) // this selects out the number of the position marked
{
    // 123456789 is supplied // position 5 // return value must be 5

    cout << "Passed Number is  : " << number_num << endl ;
    cout << "Passed Position is : " << pos << endl ;

    int a;
    a = 10;
    long int c;
    int rem;

                                // c = pow(10, pos) + 0.48 ;  // adding 0.48 because of integer truncation is use int a only if u use long int no nned

    cout << "C is  : " << c  <<  endl;

        rem = number_num % c;
        
    cout << "Rem is  : " << rem;
    return rem;
    
}