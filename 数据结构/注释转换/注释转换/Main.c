#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

/*
fopen/fclose

getchar - 文件内读 -> fgetc
putchar - 文件内写 -> fputc

printf  - 文件内打印 -> fprintf

*/

typedef enum
{
	CODE,			 // 代码状态 
	YU_DAO_XIE_GANG, // 遇到/
	C_COMMENT,		 // C风格注释
	CPP_COMMENT,	 // C++风格注释
	YU_DAO_XING,	 // C风格注释中遇到*
}	State;

// GBK 一个汉字占两个字符（char， char）
void Convert(FILE *pIn, FILE *pOut)
{
	//当前状态，CODE是出事状态
	State state = CODE;
	const char * state_desc[] = {
		"正常状态",
		"遇到 / ",
		"C 风格注释",
		"C++ 风格注释",
		"C 风格中遇到 * "
	};

	int ch;
	int nextCh;
	while (1)
	{
		//从输入文件中state_desc依次读出一个字符
		ch = fgetc(pIn);

		//处理读完文件的情况
		if (ch == EOF)
		{
			break;
		}

		printf("读到字符: %c，当前状态: %s --> ", (char)ch, state_desc[state]);

		// 根据当前状态 + 读到的字符，决定下个状态
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
				//上一个*
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