#include <iostream>
#include <math.h>

using namespace std;

/*
**�ҵ�1~100֮�������
*/
void Prime(int first,int end)
{
	int cur = 0;
	int i,j;
	for (i = first; i < end; i++)
	{
		cur = sqrt(i);
		for (j = 0; j <= cur; j++)
		{
			if (cur%j == 0)
			{
				break;
			}
			if (j >= cur + 1)
			{
				cout << i << "  " << endl;
			}
		}
	}
}

int main()
{
	Prime(1, 100);
	return 0;
}