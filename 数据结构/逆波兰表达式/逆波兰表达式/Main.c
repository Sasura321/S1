#include "Stack.h"

//逆波兰表达式（Reverse Polish Notion） /  后序表达式
typedef enum {
	OPERAND,	// 操作数类型
	OPERATOR	// 操作符类型
}	Type;

typedef enum {
	ADD, SUB, MUL, DIV
}	Operator;

typedef struct {
	Type type;
	int	operand;		// 操作数
	Operator operator;		// 操作符
}	Element;

int Run(Operator operator, int a, int b)
{
	switch (operator) {
	case ADD:
		return a + b;
	default:
		// 不应该出现
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
			// 不应该出现
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
			SUB	// 这个其实没有用，随便写
		},
		{
			OPERAND,
			2,
			SUB	// 这个其实没有用，随便写
		},
		{
			OPERATOR,
			-1,	// 这个其实没有用，随便写
			ADD
		},
		{
			OPERAND,
			3,
			SUB	// 这个其实没有用，随便写
		},
		{
			OPERATOR,
			-1,	// 这个其实没有用，随便写
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