//������C�汾

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct BiTNode {//���������
    char data;                      //����
    struct BiTNode *lchild,*rchild; //���Һ���ָ��
} BiTNode,*BiTree;

int nn=0;
int CreateBiTree(BiTree *T) {//���������д���������
    char data;
    scanf("%c",&data);//�������������������н���ֵ��һ���ַ�������#����ʾ����
    if (data == '#') {
        *T = NULL;
    } else {
        *T = (BiTree)malloc(sizeof(BiTNode)); nn++;
        (*T)->data = data;         //���ɸ����
        CreateBiTree(&(*T)->lchild);//����������
        CreateBiTree(&(*T)->rchild);//����������
    }
    return 0;
}
void Visit(BiTree T) {//���
    if (T->data != '#') {
        printf("%c ",T->data);
    }
}
void PreOrder(BiTree T) {//�������
    if (T != NULL) {
        Visit(T);               //���ʸ��ڵ�
        PreOrder(T->lchild);    //�������ӽ��
        PreOrder(T->rchild);    //�������ӽ��
    }
}
void InOrder(BiTree T) {//�������
    if (T != NULL) {
        InOrder(T->lchild);     //�������ӽ��
        Visit(T);               //���ʸ��ڵ�
        InOrder(T->rchild);     //�������ӽ��
    }
}
void PostOrder(BiTree T) {//�������
    if (T != NULL) {
        PostOrder(T->lchild);   //�������ӽ��
        PostOrder(T->rchild);   //�������ӽ��
        Visit(T);               //���ʸ��ڵ�
    }
}
void PreOrder2(BiTree T) {//�������(�ǵݹ�)
//����T->data�󣬽�T��ջ������������������������������ʱ��ջ��Ԫ��ӦΪT����ջ�����������T����������
    BiTree *stack=(BiTree *)malloc(nn*sizeof(BiTree));
    int sp=0;
    BiTree p = T;//p�Ǳ���ָ��
    while (p || sp) {   //ջ���ջ���p����ʱѭ��
        if (p != NULL) {
            stack[sp]=p;sp++;       //����ջ��
            printf("%c ",p->data);  //���ʸ��ڵ�
            p = p->lchild;          //����������
        } else {
            sp--;p=stack[sp];       //��ջ
            p = p->rchild;          //����������
        }
    }
    free(stack);
}
void InOrder2(BiTree T) {//�������(�ǵݹ�)
//T��Ҫ�������ĸ�ָ�룬�������Ҫ���ڱ������������󣬷��ʸ����ٱ�����������
//�Ƚ�T��ջ������������������������������ʱ��ջ��Ԫ��ӦΪT����ջ������T->data�����������T����������
    BiTree *stack=(BiTree *)malloc(nn*sizeof(BiTree));
    int sp=0;
    BiTree p = T;//p�Ǳ���ָ��
    while (p || sp) {   //ջ���ջ���p����ʱѭ��
        if (p != NULL) {
            stack[sp]=p;sp++;       //����ջ��
            p = p->lchild;          //����������
        } else {
            sp--;p=stack[sp];       //��ջ
            printf("%c ",p->data);
            p = p->rchild;          //����������
        }
    }
    free(stack);
}

typedef struct BiTNodePost{
    BiTree biTree;
    char tag;
} BiTNodePost,*BiTreePost;
void PostOrder2(BiTree T) {//�������(�ǵݹ�)
    BiTreePost *stack=(BiTreePost *)malloc(nn*sizeof(BiTreePost));
    int sp=0;
    BiTree p = T;//p�Ǳ���ָ��
    BiTreePost BT;
    while (p != NULL || sp) {//ջ���ջ���p����ʱѭ��
        while (p != NULL) {//����������
            BT = (BiTreePost)malloc(sizeof(BiTNodePost));
            BT->biTree = p;
            BT->tag = 'L';//���ʹ�������
            stack[sp]=BT;sp++;       //����ջ��
            p = p->lchild;
        }
        while (sp && (stack[sp-1])->tag == 'R') {//��������������Ϸ��ʸ��ڵ�
            sp--;BT=stack[sp];        //��ջ
            printf("%c ",BT->biTree->data);
            free(BT);
        }
        if (sp) {//����������
            BT=stack[sp-1];
            BT->tag = 'R';//���ʹ�������
            p = BT->biTree;
            p = p->rchild;
        }
    }
    free(stack);
}
void LevelOrder(BiTree T) {//��α���
    BiTree p;
    BiTree *queue;
    int h=0,t=0,n=0;

    if (T == NULL) return;
    p=T;
    queue=(BiTree *)malloc(nn*sizeof(BiTree));
    queue[t]=p;t=(t+1)%10;n++;//���ڵ����
    while (n) {    //���в���ѭ��
        p=queue[h];             //��ͷԪ�س���
        printf("%c ",p->data);  //����pָ��Ľ��
        h=(h+1)%10;n--;         //�˳�����
        if (p->lchild != NULL) {//���������գ������������
            queue[t]=p->lchild;t=(t+1)%10;n++;
        }
        if (p->rchild != NULL) {//���������գ������������
            queue[t]=p->rchild;t=(t+1)%10;n++;
        }
    }
    free(queue);
}
int main() {
    BiTree T;

    setlocale(LC_ALL,"chs");
    CreateBiTree(&T);

    printf("�������        ��");PreOrder  (T);printf("\n");
    printf("�������(�ǵݹ�)��");PreOrder2 (T);printf("\n");
                                               printf("\n");
    printf("�������        ��");InOrder   (T);printf("\n");
    printf("�������(�ǵݹ�)��");InOrder2  (T);printf("\n");
                                               printf("\n");
    printf("�������        ��");PostOrder (T);printf("\n");
    printf("�������(�ǵݹ�)��");PostOrder2(T);printf("\n");
                                               printf("\n");
    printf("��α���        ��");LevelOrder(T);printf("\n");

    return 0;
}
//ABC##DE#G##F###
//�������        ��A B C D E G F
//�������(�ǵݹ�)��A B C D E G F
//
//�������        ��C B E G D F A
//�������(�ǵݹ�)��C B E G D F A
//
//�������        ��C G E F D B A
//�������(�ǵݹ�)��C G E F D B A
//
//��α���        ��A B C D E F G
//

///       A
///      /
///     B
///    / \
///   C   D
///      / \
///     E   F
///      \
///       G
