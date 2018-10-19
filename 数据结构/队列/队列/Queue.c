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

//��ʼ��
void QueueInit(Queue *pQueue)
{
	pQueue->front = pQueue->rear = NULL;
}

//����
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

//����ռ�
static QNode *CreateNode(QDataType data)
{
	QNode *node = (QNode*)malloc(sizeof(QNode));
	assert(node);
	node->data = data;
	node->next = NULL;

	return node;
}

// ���루β�壩
void QueuePush(Queue *pQueue, QDataType data)
{
	QNode *newNode = CreateNode(data);

	//����Ϊ��
	if (pQueue->front == NULL)
	{
		pQueue->front = pQueue->rear = newNode;
		return;
	}

	pQueue->rear->next = newNode;
	pQueue->rear = newNode;
}

//ɾ����ͷɾ��
void QueuePop(Queue *pQueue)
{
	assert(pQueue != NULL);			//��ַ��Ҫ��Ч
	assert(pQueue->front != NULL);  //����Ϊ�գ���֧��

	QNode *del = pQueue->front;
	pQueue->front = pQueue->front->next;
	free(del);

	//������ֻ��һ���ڵ�
	if (pQueue->front == NULL)
	{
		pQueue->rear = NULL;
	}
}

//�鿴����Ԫ��
QDataType QueueFront(Queue *pQueue)
{
	assert(pQueue != NULL);
	assert(pQueue->front != NULL);

	return pQueue->front->data;
}

//�Ƿ�Ϊ��
int QueueEmpty(const Queue *pQueue)
{
	return pQueue->front == NULL;
}

//��������Ԫ��
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