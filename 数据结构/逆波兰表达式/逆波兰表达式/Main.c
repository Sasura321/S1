#include "Stack.h"

//�沨�����ʽ��Reverse Polish Notion�� /  ������ʽ
typedef enum {
	OPERAND,	// ����������
	OPERATOR	// ����������
}	Type;

typedef enum {
	ADD, SUB, MUL, DIV
}	Operator;

typedef struct {
	Type type;
	int	operand;		// ������
	Operator operator;		// ������
}	Element;

int Run(Operator operator, int a, int b)
{
	switch (operator) {
	case ADD:
		return a + b;
	default:
		// ��Ӧ�ó���
		assert(0);
	}
}

int ReversePolishNotion(Element expression[], int size)
{
	Stack stack;
	StackInit(&stack);
	int op1, op2;
	int result;

	for (int i = 0; i < size; i++) {
		Element e = expression[i];

		switch (e.type) {
		case OPERAND:
			StackPush(&stack, e.operand);
			break;
		case OPERATOR:
			op1 = StackTop(&stack); StackPop(&stack);
			op2 = StackTop(&stack); StackPop(&stack);

			result = Run(e.operator, op1, op2);

			StackPush(&stack, result);
			break;
		default:
			// ��Ӧ�ó���
			assert(0);
		}
	}

	assert(StackSize(&stack) == 1);
	result = StackTop(&stack);

	return result;
}

void TestRPN()
{
	// 1 + 2 + 3
	// 1 2 + 3 +
	Element expression[] = {
		{
			OPERAND,
			1,
			SUB	// �����ʵû���ã����д
		},
		{
			OPERAND,
			2,
			SUB	// �����ʵû���ã����д
		},
		{
			OPERATOR,
			-1,	// �����ʵû���ã����д
			ADD
		},
		{
			OPERAND,
			3,
			SUB	// �����ʵû���ã����д
		},
		{
			OPERATOR,
			-1,	// �����ʵû���ã����д
			ADD
		}
	};

	int result = ReversePolishNotion(expression, 5);

	printf("result = %d\n", result);
}

int  main()
{
	TestRPN();
	return 0;
}