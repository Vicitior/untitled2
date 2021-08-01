#include <stdlib.h>

#include <stdio.h>

//函数结果状态代码

#define MAXSIZE 10

#define OK 1

#define TRUE 1

#define FALSE 0

typedef int CQElement;

typedef int Status;

typedef struct Queue {

CQElement data[MAXSIZE];

       int front;

       int rear;

}CircularQueue;

//--------------基本操作函数原型说明---------------------------------//

Status InitQueue(CircularQueue&Q);/* 初始化队列 */

Status DisplayQueue(CircularQueue Q);/* 输出队列中所有元素 */

int GetLength(CircularQueue Q);/* 获取队列的长度 */

Status EnQueue(CircularQueue&Q, CQElement e);/* 入队 */

Status DeQueue(CircularQueue&Q, CQElement&e);/* 出队 */

int main(int argc, char** argv){

CircularQueueCQueue;

       int idx;

CQElement data;

       while (1)

       {

printf("//*************队列基本操作实验*************//\n");

printf("1、队列的初始化     　　 2、取队列的长度\n");

printf("3、队列尾部插入元素　　  4、删除队首元素\n");

printf("5、输出队列中所有元素    0、退出\n");

printf("请选择（0-5）：");

idx = getchar();

              switch (idx)

              {

              case '1':

InitQueue(CQueue);

                     break;

              case '2':

printf("队列的长度是：%d\n", GetLength(CQueue));

                     break;

              case '3':

printf("请输入入队元素:");

scanf("%d", &data);

EnQueue(CQueue, data);

                     break;

              case '4':

DeQueue(CQueue, data);

                     break;

              case '5':

DisplayQueue(CQueue);

                     break;

              case '0':

                     exit(0);

              default:

printf("非法输入，请输入正确的选择（0-5）,");

              }

printf("按任意键继...");

getchar();

       }

       return 0;

}

Status InitQueue(CircularQueue&Q)

{

       int i = 0;

Q.front = 0;

Q.rear = 0;

       for (i = 0; i<MAXSIZE; i++)

       {

Q.data[i] = 0;

       }

       return OK;

}

Status EnQueue(CircularQueue&Q, CQElement e)

{

       if ((Q.rear + 1) % MAXSIZE == Q.front)

              return FALSE;

Q.data[Q.rear] = e;

Q.rear =_______⑴__________;

       return OK;

}

Status DeQueue(CircularQueue&Q, CQElement&e)

{

       if (Q.front == Q.rear)

              return FALSE;

       e = Q.data[Q.front];

Q.front = ______⑵ ________ ;

       return OK;

}

int GetLength(CircularQueue Q)

{

       return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;

}

Status DisplayQueue(CircularQueue Q)

{

       int i;

       int len = GetLength(Q);

printf("front->");

       for (i = 0; i<len; i++) {

              if (Q.front + i<MAXSIZE)

printf("%d->", Q.data[Q.front + i]);

              else

printf("%d->",______⑶_______);

       }

printf("rear\n");

return OK;

}