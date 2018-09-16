#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXSIZE 100

typedef int ElemType;

typedef struct
{
    ElemType data[MAXSIZE];
    int length;
}Sqlist;


void swap(ElemType &a, ElemType &b)
{
    ElemType c;
    c = a;
    a = b;
    b = c;
}

void divide(Sqlist *&L)
{
    int i = 0;
    int j = L->length-1;
    int temp = 0;

    while(1)
    {
        for (; i < L->length; i++)
            if (L->data[i] % 2 == 0)
                break;

        for (; j > i; j--)
            if (L->data[j] % 2 == 1)
                break;

        if (i < j)
            swap(L->data[i], L->data[j]);
        else
            break;

        /*
        if((L->data[i]%2)==0)
        {
            temp = L->data[i];
        }
        else
        {
            i++;
        }
        if((L->data[j]%2)==1)
        {
            L->data[i] = L->data[j];
            L->data[j] = temp;
        }
        else
        {
            j--;
        }
        */
    }
}

void print_list(Sqlist *s)
{
    int i;

    for(i=0; i< s->length; i++)
        printf("%d ", s->data[i]);
    putchar(10);
}

int main()
{
    Sqlist *L, s;
    int n, i;
    printf("Input the number of list: ");
    scanf("%d", &n);
    if (n > MAXSIZE)
        return 0;
    L = &s;
    srand(time(NULL));
    for (i = 0; i < n; i++)
        L->data[i] = rand() % 100;
    L->length = n;

    printf("Before swap: \n");
    print_list(L);
    divide(L);
    printf("After swap: \n");
    print_list(L);
    return 0 ;
}
