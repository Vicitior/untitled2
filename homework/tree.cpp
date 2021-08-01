#include <stdio.h>
#include <stdlib.h>
#define STACK_INIT_SIZE 50
#define STACKINCREMENT 10
#define OVERFLOW -2
#define OK 1
#define ERROR 0
typedef int Status;
typedef char TElemType;

typedef struct BiNode{
    TElemType data;
    struct BiNode *lchild, *rchild;
}BiNode, *BiTree;

typedef BiTree SElemType;
typedef struct{
    SElemType *base;
    SElemType *top;
    int stacksize;
}Stack;

typedef BiTree QElemType;
typedef struct  QNode{
    QElemType data;
    struct QNode * next;
}QNode,* QueuePtr;
typedef struct{
    QueuePtr front;
    QueuePtr rear;
}Queue;

Status CreateBiTree(BiTree &T)
{
    char ch;
    ch = getchar();
    if (ch == ' ')
    {
        T = NULL;
    }
    else
    {
        if (!(T = (BiNode * )malloc(sizeof(BiNode))))
        {
            printf("�ڴ����ʧ��\n");
            exit(OVERFLOW);
        }
        T->data = ch;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
    return OK;
}

Status PrintElement(TElemType e)
{
    printf(" %c ",e);
    return OK;
}

Status PreOrderTraverse(BiTree T, Status(* Visit)(TElemType))
{
    if(T)
    {
        if(Visit(T->data))
            if(PreOrderTraverse(T->lchild,Visit))
                if(PreOrderTraverse(T->rchild,Visit))  return OK;
        return ERROR;
    }
    else return OK;
}

Status InOrderTraverse(BiTree T,Status(* Visit)(TElemType))
{
    if(T)
    {
        if(InOrderTraverse(T->lchild,Visit))
        {
            if(Visit(T->data))
            {
                if(InOrderTraverse(T->rchild,Visit))
                {
                    return OK;
                }
            }
        }
        return ERROR;
    }
    else
    {
        return OK;
    }
}

Status PostOrderTraverse(BiTree T,Status(* Visit)(TElemType))
{
    if(T)
    {
        if(PostOrderTraverse(T->lchild,Visit))
        {
            if(PostOrderTraverse(T->rchild,Visit))
            {
                if(Visit(T->data))
                {
                    return OK;
                }
            }
        }
        return ERROR;
    }
    else
    {
        return OK;
    }
}

Status InitStack(Stack &S)
{
    if (!(S.base = (SElemType *) malloc(STACK_INIT_SIZE*sizeof(SElemType))))
    {
        printf("�ڴ����ʧ��\n");
        exit(OVERFLOW);
    }
    S.top = S.base;
    S.stacksize = STACK_INIT_SIZE;
    return OK;
}

Status DestroyStack(Stack &S)
{
    free(S.base);
    S.base = NULL;
    S.top = NULL;
    return OK;
}

Status StackEmpty(Stack S)
{
    return S.top == S.base;
}

Status Push(Stack &S, SElemType e)
{
    if (S.top - S.base >= S.stacksize)
    {
        if(!(S.base=(SElemType *)realloc(S.base,(STACK_INIT_SIZE + STACKINCREMENT)*sizeof(SElemType))))
        {
            printf("�ڴ����ʧ��\n");
            exit(OVERFLOW);
        }
        S.top = S.base +S.stacksize;
        S.stacksize+=STACK_INIT_SIZE;
    }
    *S.top++=e;
}

Status Pop(Stack &S, SElemType &e)
{
    if (StackEmpty(S))
    {
        return ERROR;
    }
    e = *--S.top;
    return OK;
}

Status GetTop(Stack S, SElemType &e)
{
    if (StackEmpty(S))
    {
        return ERROR;
    }
    e = *(S.top - 1);
    return OK;
}

Status PreOrderTraverse1(BiTree T, Status(*Visit)(TElemType))
{
    Stack S;
    InitStack(S);
    BiTree P = T;
    while (P || !(StackEmpty(S)))
    {
        if (P)
        {
            if (!Visit(P->data))
            {
                return ERROR;
            }
            Push(S, P);
            P = P->lchild;
        }
        else
        {
            Pop(S, P);
            P = P->rchild;
        }
    }
    return OK;
}

Status InOrderTraverse1(BiTree T,Status(* Visit)(TElemType))
{
    Stack S;
    InitStack(S);
    BiTree P = T;
    while (P || !(StackEmpty(S)))
    {
        if (P)
        {
            Push(S, P);
            P = P->lchild;
        }
        else
        {
            Pop(S, P);
            if (!Visit(P->data))
            {
                return ERROR;
            }
            P = P->rchild;
        }
    }
    return OK;
}

Status PostOrderTraverse1(BiTree T,Status(* Visit)(TElemType))
{
    BiTree P = T, Q = NULL;
    Stack S;
    InitStack(S);
    while (P || !(StackEmpty(S)))
    {
        while (P)
        {
            Push(S, P);
            P = P->lchild;
        }
        Q = NULL;
        while (!StackEmpty(S))
        {
            GetTop(S, P);
            if ((P->rchild == NULL) || (P->rchild == Q))
            {
                if(!Visit(P->data))
                {
                    return ERROR;
                }
                if(P == T)
                {
                    return ERROR;
                }
                Q = P;
                Pop(S, P);
            }
            else
            {
                P = P->rchild;
                break;
            }
        }
    }
    return OK;
}

Status BiTreeDepth(BiTree T)
{
    Status thigt, leftthigt, rightthigt;
    if (!T)
    {
        return ERROR;
    }
    else
    {
        leftthigt = BiTreeDepth(T->lchild);
        rightthigt = BiTreeDepth(T->rchild);
        if (leftthigt >= rightthigt)
        {
            thigt = leftthigt + 1;
        }
        else
        {
            thigt = rightthigt + 1;
        }
    }
    return thigt;
}

int NodeSubNum(BiTree T)
{
    if (!T)
    {
        return ERROR;
    }
    else
    {
        return(NodeSubNum(T->lchild) + NodeSubNum(T->rchild) + 1);
    }
}

int main()
{
    BiTree T;
    printf("��������Ҫ�������������������У�\n");
    CreateBiTree(T);
    printf("\n�������ı���");
    printf("\n\n��������ݹ��㷨�����");
    PreOrderTraverse(T,PrintElement);
    printf("\n\n��������ݹ��㷨�����");
    InOrderTraverse(T,PrintElement);
    printf("\n\n��������ݹ��㷨�����");
    PostOrderTraverse(T,PrintElement);
    printf("\n\n��������ǵݹ��㷨�����");
    PreOrderTraverse1(T,PrintElement);
    printf("\n\n��������ǵݹ��㷨�����");
    InOrderTraverse1(T,PrintElement);
    printf("\n\n��������ǵݹ��㷨�����");
    PostOrderTraverse1(T,PrintElement);
    printf("\n����������Ϣ");
    printf("\n�ö������ĸ߶ȣ�%d",BiTreeDepth(T));
    printf("\n�ö������ܽ������%d",NodeSubNum(T));
    getchar();
    getchar();
    return 0;
}