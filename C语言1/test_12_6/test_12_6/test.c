#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef int ElemType;
typedef struct
{
    ElemType data[MAXSIZE];
    int length;
}Sqlist;

void divide(Sqlist *&L)
{
    int i = 0;
    int j = L->length-1;
    int temp = 0;

    while(i<j)
    {
        for (i<j; i < L->length; i++)
            if (L->data[i] % 2 == 0)
                break;

        for (i<j; j > i; j--)
            if (L->data[j] % 2 != 0)
                break;

        if (i < j)
		{
			int temp = 0;
			temp = L->data[i];
            L->data[i] = L->data[j];
			L->data[j] = temp;
		}  
        else
            break;
    }
}

int main()
{
    Sqlist *L;
	int L->data[] = {0,1,2,3,4,5,6,7,8,9};
	int L->length = 10;
    divide(L);
    return 0 ;
}
