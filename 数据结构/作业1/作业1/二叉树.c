#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct TreeNode {
	int	data;
	struct TreeNode *left;
	struct TreeNode *right;
} TreeNode;

/*
*  1. ����ǰ������򹹽�������;
*/
TreeNode *CreateTree(int preOrder[], int inOrder[], int size)
{
	// ��������������գ�
	if (size == 0){
		return 0;
	}

	//��ǰ���ҵ������
	int rootValue = preOrder[0];

	//�������ҵ������±�
	int rootIn = -1;
	for (int i = 0; i < size; i++){
		if (inOrder[i] == rootValue){
			rootIn = i;
		}
	}

	//�����½��
	TreeNode *root = (TreeNode*)malloc(sizeof(TreeNode));
	root->data = rootValue;
	root->left = root->right = NULL;
	
	//�������ҽ��
	root->left = CreateTree(preOrder + 1, inOrder, rootIn);
	root->right = CreateTree(preOrder + 1 + rootIn, inOrder + 1 + rootIn, size - 1 - rootIn);

	return root;
}

/*
*  2. �ݹ鷽ʽ���ڶ��������ж�һ������Ƿ����
*/
TreeNode * Find(TreeNode *root,int data)
{
	// ����
	if (root == NULL){
		return NULL;
	}

	// �ڸ�����ҵ�
	if (root->data == data){
		return root;
	}

	// ����������
	TreeNode *value = Find(root->left, data);
	if (value != NULL){
		return value;
	}

	// ����������
	value = Find(root->right, data);
	if (value != NULL){
		return value;
	}

	// û�ҵ�
	return NULL;
}

// ��ӡ
void HandleNode(TreeNode *node)
{
	printf("%d  ", node->data);
}

/*
*����
*/
typedef struct BTreeNode *QDataType;
typedef struct QNode {
	QDataType data1;
	struct QNode *next;
}	QNode;

typedef struct Queue {
	QNode *front;
	QNode *rear;
}	Queue;

// ��ʼ��
void QueueInit(Queue *pQueue)
{
	pQueue->front = pQueue->rear = NULL;
}

//����
void QueueDestroy(Queue *pQueue)
{
	QNode *cur, *next;
	for (cur = pQueue->front; cur != NULL; cur = next) {
		next = cur->next;
		free(cur);
	}
	pQueue->front = pQueue->rear = NULL;
}

static QNode * QCreateNode(QDataType data1)
{
	QNode *node = (QNode *)malloc(sizeof(QNode));
	assert(node);
	node->data1 = data1;
	node->next = NULL;

	return node;
}

// ���루β�壩
void QueuePush(Queue *pQueue, QDataType data1)
{
	QNode *newNode = QCreateNode(data1);	// ��Ҫ��������ռ�

	if (pQueue->front == NULL) {
		pQueue->front = pQueue->rear = newNode;
		return;
	}

	pQueue->rear->next = newNode;
	pQueue->rear = newNode;
}

// ɾ����ͷɾ��
void QueuePop(Queue *pQueue)
{
	assert(pQueue != NULL);			// ��ַ��Ҫ��Ч
	assert(pQueue->front != NULL);	// ����Ϊ�գ���֧��

	QNode *del = pQueue->front;
	pQueue->front = pQueue->front->next;
	free(del);

	// ������ֻ��һ�����
	if (pQueue->front == NULL) {
		pQueue->rear = NULL;
	}
}

// �鿴��������
QDataType QueueFront(Queue *pQueue)
{
	assert(pQueue != NULL);			// ��ַ��Ҫ��Ч
	assert(pQueue->front != NULL);	// ����Ϊ�գ���֧��

	return pQueue->front->data1;
}

// �Ƿ�Ϊ��
int QueueEmpty(const Queue *pQueue)
{
	return pQueue->front == NULL;
}

/*
*  3. �������������ÿ�����ʱ������ HandleNode ����
*/
void LevelOrder(TreeNode *root)
{
	Queue queue;
	TreeNode *front;
	QueueInit(&queue);

	// �п�
	if (root == NULL){
		return;
	}

	QueuePush(&queue, root);  //�����
	while (!QueueEmpty(&queue)){
		front = QueueFront(&queue);
		QueuePop(&queue);  //������

		if (front->left != NULL){
			QueuePush(&queue, front->left);
		}

		if (front->right != NULL){
			QueuePush(&queue, front->right);
		}

		//������� front �ڵ�
		HandleNode(&front->data);
	}

	//����
	QueueDestroy(&queue);  
}

/*
*ջ
*/
struct BTreeNode;	// �ṹ������
typedef struct BTreeNode * StackDataType;

#define	MAX_SIZE 100

typedef struct Stack {
	StackDataType array[MAX_SIZE];
	int	top;	// ��ʾ��ǰ����
}	Stack;

// ��ʼ��
void StackInit(Stack *pStack)
{
	pStack->top = 0;
}

//����
void StackDestroy(Stack *pStack)
{
	pStack->top = 0;
}

// ����ֻ�ܴ�ջ����
void StackPush(Stack *pStack, StackDataType data)
{
	assert(pStack->top < MAX_SIZE);

	pStack->array[pStack->top++] = data;
}

// ɾ��ֻ��ɾ��ջ����
void StackPop(Stack *pStack)
{
	assert(pStack->top > 0);

	pStack->top--;
}

// ȡջ��Ԫ��
StackDataType StackTop(const Stack *pStack)
{
	assert(pStack->top > 0);

	return pStack->array[pStack->top - 1];
}

//�Ƿ�Ϊ��
int StackEmpty(const Stack *pStack)
{
	return pStack->top <= 0;
}

/*
*4. �ǵݹ鷽ʽ�������������������ÿ�����ʱ������ HandleNode ����
* ���������������---������---���ڵ�
*/
void PostOrder(TreeNode *root)
{
	Stack stack;
	StackInit(&stack);
	TreeNode *last = NULL;  // last Ϊ��һ���������Ľ��
	TreeNode *cur, *top;
	cur = root;

	while (cur != NULL || !StackEmpty(&stack)){
		//����������
		while (cur != NULL){
			StackPush(&stack, cur);
			cur = cur->left;
		}

		top = StackTop(&stack);  //ȡջ��Ԫ��

		//����������
		if (top->right == NULL || top->right == last){
			StackPop(&stack);  //�������ѱ���������ջ
			HandleNode(&top->data);

			//�������Ľ��
			last = top;
		}
		else{
			//������û�б�����
			cur = top->right;
		}
	}
}

/*
*����������
*/
typedef struct BTreeNode{
	int key;
	struct BTreeNode *left;
	struct BTreeNode *right;
}	BTreeNode;

/*
*5. ���÷ǵݹ鷽ʽʵ�������������Ľ��ɾ��,�ҵ���ɾ������ 1��û�ҵ����� 0
*/

// ɾ������Ϊ�յ����
void RemoveLeftNULL(BTreeNode **root, BTreeNode *parent, BTreeNode *cur, int data)
{
	// Ҫɾ���Ľ��Ϊ�����ʱ��parent Ϊ��ʼֵ
	if (parent == NULL){
		*root = cur->right;
	}
	else{
		if (data < parent->key){
			// cur �� parent �� left
			parent->left = cur->right;
		}
		else{
			// cur �� parent �� right
			parent->right = cur->right;
		}
	}

	free(cur);
}

// ɾ���Һ���Ϊ�յ����
void RemoveRightNULL(BTreeNode **root, BTreeNode *parent, BTreeNode *cur, int data)
{
	// Ҫɾ���Ľ��Ϊ�����ʱ��parent Ϊ��ʼֵ
	if (parent == NULL){
		*root = cur->right;
	}
	else{
		if (data < parent->key){
			// cur �� parent �� left
			parent->left = cur->left;
		}
		else{
			// cur �� parent �� right
			parent->right = cur->left;
		}
	}

	free(cur);
}

// ɾ�����Һ��Ӷ���Ϊ�յ����
void RemoveLeftAndRight(BTreeNode *cur)
{
	BTreeNode *del = NULL;
	BTreeNode *delParent = NULL;

	// �������������
	del = cur->left;
	while (del->right != NULL){
		delParent = del;
		del = del->right;
	}

	cur->key = del->key;

	// Ҫɾ���Ľ��Ϊ�����ʱ��parent Ϊ��ʼֵ
	if (delParent == NULL){
		// ���������ľ��� cur ������
		cur->left = del->left;
	}
	else{
		delParent->right = del->left;
	}

	free(del);
}

// ɾ�����
int Remove(BTreeNode **root, int data)
{
	BTreeNode *cur = *root;
	BTreeNode *parent = NULL;

	while (cur != NULL) {
		//�ҵ�Ҫɾ���ĵط�
		if (data == cur->key) {
			if (cur->left == NULL) {
				// cur û������
				RemoveLeftNULL(data, parent, root, cur);
			}
			else if (cur->right == NULL) {
				// cur û���Һ���
				RemoveRightNULL(data, parent, root, cur);
			}
			else {
				// ���Һ��Ӷ���Ϊ��
				RemoveLeftAndRight(cur);
			}

			return 1;
		}

		parent = cur;
		if (data < cur->key) {
			cur = cur->left;
		}
		else {
			cur = cur->right;
		}
	}

	return 0;
}


int main()
{
	int preOrder[] = { 1,2,3,4,5,6,7,8,9,0 };
	int inOrder[] = { 3,5,4,2,6,1,8,7,9,0 };
	int size = sizeof(preOrder) / sizeof(int);

	TreeNode *root = CreateTree(preOrder, inOrder, size);

	if (Find(root, 5) != NULL){
		printf("���ҳɹ�\n");
	}
	else{
		printf("����ʧ��\n");
	}

	printf("���������>");
	LevelOrder(root); printf("\n");
	printf("���������>");
	PostOrder(root); printf("\n");

	printf("%d \n", Remove(&root, 1) );
}