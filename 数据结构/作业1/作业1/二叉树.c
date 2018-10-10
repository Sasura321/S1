#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct TreeNode {
	int	data;
	struct TreeNode *left;
	struct TreeNode *right;
} TreeNode;

/*
*  1. 利用前序和中序构建二叉树;
*/
TreeNode *CreateTree(int preOrder[], int inOrder[], int size)
{
	// 考虑特殊情况（空）
	if (size == 0){
		return 0;
	}

	//从前序找到根结点
	int rootValue = preOrder[0];

	//从中序找到根的下标
	int rootIn = -1;
	for (int i = 0; i < size; i++){
		if (inOrder[i] == rootValue){
			rootIn = i;
		}
	}

	//创建新结点
	TreeNode *root = (TreeNode*)malloc(sizeof(TreeNode));
	root->data = rootValue;
	root->left = root->right = NULL;
	
	//处理左右结点
	root->left = CreateTree(preOrder + 1, inOrder, rootIn);
	root->right = CreateTree(preOrder + 1 + rootIn, inOrder + 1 + rootIn, size - 1 - rootIn);

	return root;
}

/*
*  2. 递归方式，在二叉树中判断一个结点是否存在
*/
TreeNode * Find(TreeNode *root,int data)
{
	// 空树
	if (root == NULL){
		return NULL;
	}

	// 在根结点找到
	if (root->data == data){
		return root;
	}

	// 处理左子树
	TreeNode *value = Find(root->left, data);
	if (value != NULL){
		return value;
	}

	// 处理右子树
	value = Find(root->right, data);
	if (value != NULL){
		return value;
	}

	// 没找到
	return NULL;
}

// 打印
void HandleNode(TreeNode *node)
{
	printf("%d  ", node->data);
}

/*
*队列
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

// 初始化
void QueueInit(Queue *pQueue)
{
	pQueue->front = pQueue->rear = NULL;
}

//销毁
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

// 插入（尾插）
void QueuePush(Queue *pQueue, QDataType data1)
{
	QNode *newNode = QCreateNode(data1);	// 不要忘记申请空间

	if (pQueue->front == NULL) {
		pQueue->front = pQueue->rear = newNode;
		return;
	}

	pQueue->rear->next = newNode;
	pQueue->rear = newNode;
}

// 删除（头删）
void QueuePop(Queue *pQueue)
{
	assert(pQueue != NULL);			// 地址需要有效
	assert(pQueue->front != NULL);	// 队列为空，不支持

	QNode *del = pQueue->front;
	pQueue->front = pQueue->front->next;
	free(del);

	// 队列中只有一个结点
	if (pQueue->front == NULL) {
		pQueue->rear = NULL;
	}
}

// 查看队首数据
QDataType QueueFront(Queue *pQueue)
{
	assert(pQueue != NULL);			// 地址需要有效
	assert(pQueue->front != NULL);	// 队列为空，不支持

	return pQueue->front->data1;
}

// 是否为空
int QueueEmpty(const Queue *pQueue)
{
	return pQueue->front == NULL;
}

/*
*  3. 层序遍历，遍历每个结点时，调用 HandleNode 函数
*/
void LevelOrder(TreeNode *root)
{
	Queue queue;
	TreeNode *front;
	QueueInit(&queue);

	// 判空
	if (root == NULL){
		return;
	}

	QueuePush(&queue, root);  //入队列
	while (!QueueEmpty(&queue)){
		front = QueueFront(&queue);
		QueuePop(&queue);  //出队列

		if (front->left != NULL){
			QueuePush(&queue, front->left);
		}

		if (front->right != NULL){
			QueuePush(&queue, front->right);
		}

		//层序遍历 front 节点
		HandleNode(&front->data);
	}

	//销毁
	QueueDestroy(&queue);  
}

/*
*栈
*/
struct BTreeNode;	// 结构体声明
typedef struct BTreeNode * StackDataType;

#define	MAX_SIZE 100

typedef struct Stack {
	StackDataType array[MAX_SIZE];
	int	top;	// 表示当前个数
}	Stack;

// 初始化
void StackInit(Stack *pStack)
{
	pStack->top = 0;
}

//销毁
void StackDestroy(Stack *pStack)
{
	pStack->top = 0;
}

// 增（只能从栈顶）
void StackPush(Stack *pStack, StackDataType data)
{
	assert(pStack->top < MAX_SIZE);

	pStack->array[pStack->top++] = data;
}

// 删（只能删除栈顶）
void StackPop(Stack *pStack)
{
	assert(pStack->top > 0);

	pStack->top--;
}

// 取栈顶元素
StackDataType StackTop(const Stack *pStack)
{
	assert(pStack->top > 0);

	return pStack->array[pStack->top - 1];
}

//是否为空
int StackEmpty(const Stack *pStack)
{
	return pStack->top <= 0;
}

/*
*4. 非递归方式后序遍历二叉树，遍历每个结点时，调用 HandleNode 函数
* 后序遍历：左子树---右子树---根节点
*/
void PostOrder(TreeNode *root)
{
	Stack stack;
	StackInit(&stack);
	TreeNode *last = NULL;  // last 为上一个被遍历的结点
	TreeNode *cur, *top;
	cur = root;

	while (cur != NULL || !StackEmpty(&stack)){
		//遍历左子树
		while (cur != NULL){
			StackPush(&stack, cur);
			cur = cur->left;
		}

		top = StackTop(&stack);  //取栈顶元素

		//遍历右子树
		if (top->right == NULL || top->right == last){
			StackPop(&stack);  //右子树已被遍历，出栈
			HandleNode(&top->data);

			//被遍历的结点
			last = top;
		}
		else{
			//右子树没有被遍历
			cur = top->right;
		}
	}
}

/*
*搜索二叉树
*/
typedef struct BTreeNode{
	int key;
	struct BTreeNode *left;
	struct BTreeNode *right;
}	BTreeNode;

/*
*5. 利用非递归方式实现搜索二叉树的结点删除,找到并删除返回 1，没找到返回 0
*/

// 删除左孩子为空的情况
void RemoveLeftNULL(BTreeNode **root, BTreeNode *parent, BTreeNode *cur, int data)
{
	// 要删除的结点为根结点时，parent 为初始值
	if (parent == NULL){
		*root = cur->right;
	}
	else{
		if (data < parent->key){
			// cur 是 parent 的 left
			parent->left = cur->right;
		}
		else{
			// cur 是 parent 的 right
			parent->right = cur->right;
		}
	}

	free(cur);
}

// 删除右孩子为空的情况
void RemoveRightNULL(BTreeNode **root, BTreeNode *parent, BTreeNode *cur, int data)
{
	// 要删除的结点为根结点时，parent 为初始值
	if (parent == NULL){
		*root = cur->right;
	}
	else{
		if (data < parent->key){
			// cur 是 parent 的 left
			parent->left = cur->left;
		}
		else{
			// cur 是 parent 的 right
			parent->right = cur->left;
		}
	}

	free(cur);
}

// 删除左右孩子都不为空的情况
void RemoveLeftAndRight(BTreeNode *cur)
{
	BTreeNode *del = NULL;
	BTreeNode *delParent = NULL;

	// 找左子树中最大
	del = cur->left;
	while (del->right != NULL){
		delParent = del;
		del = del->right;
	}

	cur->key = del->key;

	// 要删除的结点为根结点时，parent 为初始值
	if (delParent == NULL){
		// 左孩子中最大的就是 cur 的左孩子
		cur->left = del->left;
	}
	else{
		delParent->right = del->left;
	}

	free(del);
}

// 删除结点
int Remove(BTreeNode **root, int data)
{
	BTreeNode *cur = *root;
	BTreeNode *parent = NULL;

	while (cur != NULL) {
		//找到要删除的地方
		if (data == cur->key) {
			if (cur->left == NULL) {
				// cur 没有左孩子
				RemoveLeftNULL(data, parent, root, cur);
			}
			else if (cur->right == NULL) {
				// cur 没有右孩子
				RemoveRightNULL(data, parent, root, cur);
			}
			else {
				// 左右孩子都不为空
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
		printf("查找成功\n");
	}
	else{
		printf("查找失败\n");
	}

	printf("层序遍历：>");
	LevelOrder(root); printf("\n");
	printf("后序遍历：>");
	PostOrder(root); printf("\n");

	printf("%d \n", Remove(&root, 1) );
}