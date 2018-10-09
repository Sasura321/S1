#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

/*
fopen/fclose

getchar - �ļ��ڶ� -> fgetc
putchar - �ļ���д -> fputc

printf  - �ļ��ڴ�ӡ -> fprintf

*/

typedef enum
{
	CODE,			 // ����״̬ 
	YU_DAO_XIE_GANG, // ����/
	C_COMMENT,		 // C���ע��
	CPP_COMMENT,	 // C++���ע��
	YU_DAO_XING,	 // C���ע��������*
}	State;

// GBK һ������ռ�����ַ���char�� char��
void Convert(FILE *pIn, FILE *pOut)
{
	//��ǰ״̬��CODE�ǳ���״̬
	State state = CODE;
	const char * state_desc[] = {
		"����״̬",
		"���� / ",
		"C ���ע��",
		"C++ ���ע��",
		"C ��������� * "
	};

	int ch;
	int nextCh;
	while (1)
	{
		//�������ļ���state_desc���ζ���һ���ַ�
		ch = fgetc(pIn);

		//��������ļ������
		if (ch == EOF)
		{
			break;
		}

		printf("�����ַ�: %c����ǰ״̬: %s --> ", (char)ch, state_desc[state]);

		// ���ݵ�ǰ״̬ + �������ַ��������¸�״̬
		switch (state)
		{
		case CODE:
			if (ch == '/')
			{
				state = YU_DAO_XIE_GANG;
			}
			fputc(ch, pOut);
			break;
		case YU_DAO_XIE_GANG:
			if (ch == '/')
			{
				state = CPP_COMMENT;
				fputc(ch, pOut);
			}
			else if (ch = '*')
			{
				state = C_COMMENT;
				fputc(ch, pOut);
			}
			else
			{
				state = CODE;
				fputc(ch, pOut);
			}
			break;
		case C_COMMENT:
			if (ch == '*')
			{
				state = YU_DAO_XING;
			}
			else
			{
				fputc(ch, pOut);
				if (ch == '\n')
				{
					fprintf(pOut, "//");
				}
			}
			break;
		case CPP_COMMENT:
			if (ch == '*')
			{
				state = YU_DAO_XING;
			}
			else
			{
				fputc(ch, pOut);
			}
			break;
		case YU_DAO_XING:
			if (ch == '/')
			{
				state = CODE;
				nextCh = fgetc(pIn);
				if (nextCh != '\n')
				{
					fputc('\n', pOut);
				}
				ungetc(nextCh, pIn);
			}
			else if (ch != '*')
			{
				state = C_COMMENT;
				fputc('*', pOut);
				fputc(ch, pOut);
			}
			else
			{
				//��һ��*
				fputc('*', pOut);
			}
			break;
		}

		printf("%s\n", state_desc[state]);
	}
}

int main()
{
	FILE *pIn = fopen("input.c", "r");
	if (pIn == NULL)
	{
		perror("fopen input");
		return 1;
	}

	// a ---> append
	FILE *pOut = fopen("output.c", "w");
	if (pOut == NULL)
	{
		perror("fopen output");
		fclose(pIn);
		return 1;
	}

	Convert(pIn, pOut);

	fclose(pOut);
	fclose(pIn);

	return 0;
}