#include <stdlib.h>
#include <assert.h>

typedef int QDataType;

typedef struct QNode
{
	QDataType data;
	struct QNode *next;
}	QNode;

typedef struct Queue
{
	QNode *front;
	QNode *rear;
}	Queue;

//初始化
void QueueInit(Queue *pQueue)
{
	pQueue->front = pQueue->rear = NULL;
}

//销毁
void QueueDestory(Queue *pQueue)
{
	QNode *cur = 0;
	QNode *next = 0;

	for (cur = pQueue->front; cur != NULL; cur = next)
	{
		next = cur->next;
		free(cur);
	}
	pQueue->front = pQueue->rear = NULL;
}

//申请空间
static QNode *CreateNode(QDataType data)
{
	QNode *node = (QNode*)malloc(sizeof(QNode));
	assert(node);
	node->data = data;
	node->next = NULL;

	return node;
}

// 插入（尾插）
void QueuePush(Queue *pQueue, QDataType data)
{
	QNode *newNode = CreateNode(data);

	//队列为空
	if (pQueue->front == NULL)
	{
		pQueue->front = pQueue->rear = newNode;
		return;
	}

	pQueue->rear->next = newNode;
	pQueue->rear = newNode;
}

//删除（头删）
void QueuePop(Queue *pQueue)
{
	assert(pQueue != NULL);			//地址需要有效
	assert(pQueue->front != NULL);  //队列为空，不支持

	QNode *del = pQueue->front;
	pQueue->front = pQueue->front->next;
	free(del);

	//队列中只有一个节点
	if (pQueue->front == NULL)
	{
		pQueue->rear = NULL;
	}
}

//查看队首元素
QDataType QueueFront(Queue *pQueue)
{
	assert(pQueue != NULL);
	assert(pQueue->front != NULL);

	return pQueue->front->data;
}

//是否为空
int QueueEmpty(const Queue *pQueue)
{
	return pQueue->front == NULL;
}

//返回数据元素
int QueueSize(const Queue *pQueue)
{
	int size = 0;
	Queue *cur = 0;
	for (cur = pQueue->front; cur != NULL; cur = cur->rear)
	{
		size++;
	}
	return size;
}