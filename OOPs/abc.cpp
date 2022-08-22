//Program to return the number of the input position

#include <iostream>
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
    cout << count ;
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

cout << "Rev is  : " << *(reverse);



}