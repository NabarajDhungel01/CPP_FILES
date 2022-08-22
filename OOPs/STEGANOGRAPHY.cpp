// Program to encrypt and decrypt the provided input
// 7  8  9  // 0-> differentiator               8->a  88->b  888->c      9->d  99->e  999->f
// 4  5  6  // 4->g  44->h  444->i              5->j  55->k  555->l      6->m  66->n  666->o
// 1  2  3  // 1->p  11->q  111->r 1111->s      2->t  22->u  222->v      3->w  33->x  333->y 3333->z
//
// SPACE - 7
// For eg :- 6080222033376609901080555     =>   NAVY NEPAL

// USING POINTERS

#include <iostream>
#include <math.h> // for pow()
using namespace std;
int n_number(int number_num,int pos); // this selects out the number of the position marked
char switch_alphabet(int number, char *ra, int *n, int *v);
char alphabets[] = {'A', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};



// char *ptr_alpha;
// ptr_alpha = (char *)malloc(sizeof(char));

int main()
{
    //     for (int i = 0; i < 27; i++)
    //     {
    //     cout << alphabets[i];
    //     }
    int passing_num;

    int num;
    // cout << "Enter your number to decode  : ";
    // cin >> num;
    num = 123456789;

    int *ptr_num;
    ptr_num = &num;

    int value;
    int *ptr_value;

    char returned_alpha;
    char *ptr_ra;
    ptr_ra = &returned_alpha;

    passing_num = n_number(num,2);

    cout << " Passing Num is  : " << passing_num;

    switch_alphabet(passing_num, ptr_ra, ptr_num, ptr_value);

    cout << "Returned Alphabet is : " << *ptr_ra;
    // cout<< *(ptr+1);
    // cout << alphabets[0];

    // value =  switch_alphabet(ptr_alpha,ptr_num,ptr_value);
    return 0;
}

char switch_alphabet(int number, char *ra, int *n, int *v)
{
    switch (number)
    {
    case 8:
        *ra = 'a';
        break;

    default:
        cout << endl
             << "Work on Progess" << endl;
        break;
    }
}

