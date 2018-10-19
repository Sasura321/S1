#include "Stack.h"

//����ƥ��
void BracketMatch(const char *sequence, int size)
{
	Stack stack;
	StackInit(&stack);
	char ch;
	char leftBracket;

	for (int i = 0; i < size; i++)
	{
		ch = sequence[i];

		switch (ch)
		{
		case '(':
		case '[':
		case '{':
			StackPush(&stack, (StackDataType)ch);
		case ')':
		case ']':
		case '}':
			if (StackEmpty(&stack))
			{
				printf("�����Ŷ�\n");
				StackDestory(&stack);
				return;
			}

			leftBracket = (char)StackTop(&stack);
			StackPop(&stack);

			if (leftBracket == '(' && ch != ')')
			{
				printf("��ƥ��\n");
				return;
			}

			if (leftBracket == '[' && ch != ']')
			{
				printf("��ƥ��\n");
				return;
			}

			if (leftBracket == '{' && ch != '}')
			{
				printf("��ƥ��\n");
				return;
			}
		default:
			break;
		}
	}

	if (!StackEmpty(&stack))
	{
		printf("�����Ŷ�\n");
		return;
	}

	printf("����ƥ��\n");
}

//����
void TestBracket()
{
	const char * seqs[] = {
		"(())abc{[(])}",
		"(()))abc{[]}",
		"(()()abc{[]}",
		"(())abc{[]()}"
	};

	for (int i = 0; i < 4; i++) {
		BracketMatch(seqs[i], strlen(seqs[i]));
	}
}

int main()
{
	TestBracket();
	return 0;
}