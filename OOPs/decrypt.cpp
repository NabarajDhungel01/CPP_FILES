// Program to encrypt and decrypt the provided input
// 7  8  9  // 0-> differentiator               8->a  88->b  888->c      9->d  99->e  999->f
// 4  5  6  // 4->g  44->h  444->i              5->j  55->k  555->l      6->m  66->n  666->o
// 1  2  3  // 1->p  11->q  111->r 1111->s      2->t  22->u  222->v      3->w  33->x  333->y 3333->z
//
// SPACE - 7
// For eg :- 6080222033376609901080555     =>   NAVY NEPAL

// USING POINTERS

#include <iostream>
using namespace std;
char switch_alphabet(char *ra, int *n, int *v);
char alphabets[] = {'A', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
// char *ptr_alpha;
// ptr_alpha = &alphabets[0];
int main()
{
    for (int i = 0; i < 27; i++)
    {
    cout << alphabets[i];
    }
    

                        //     int num[1000];
                        //     num[0] = 9;
                        //     int *ptr_num;
                        //     ptr_num = &num[0];

                        //     int value;
                        //     int *ptr_value;

                        //     char returned_alpha;
                        //     char *ptr_ra;
                        //     ptr_ra = &returned_alpha;

                        //     cout << "Returned Alphabet is" << *ptr_ra;
                        //     // cout<< *(ptr+1);
                        //     // cout << alphabets[0];

                        //     // value =  switch_alphabet(ptr_alpha,ptr_num,ptr_value);
                        //     return 0;
}

char switch_alphabet(char *ra, int *n, int *v)
{
    switch (*v)
    {
    case 8:
        *ra = 'a' ;
        break;

    default:
        cout<< "Work on Progess";
        break;
    }
}
