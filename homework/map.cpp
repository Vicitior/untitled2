#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NAME 5
#define MAX_INFO 20
#define INF 0x3f3f3f3f
#define MAX_VEX_NUM 20
using namespace std;

typedef int VRType;
typedef char InfoType;
typedef char VertexType[MAX_NAME];
typedef struct QNode
{
    int data;
    struct QNode *qnext;
}QNode, *PQNode;

typedef struct Queue
{
    PQNode front;
    PQNode rear;
}Queue, *PQunue;

typedef struct
{
    VRType adj;
    InfoType *info;
}ArcCell, AdjMatrix[MAX_VEX_NUM][MAX_VEX_NUM];

//定义图
typedef struct
{
    VertexType vexs[MAX_VEX_NUM];
    AdjMatrix arcs;
    int vexnum, arcnum;
    int kind;
}MGraph;

int j, i, k, l, IncInfo, w;
char s[MAX_INFO], *info;
int vis[MAX_VEX_NUM] = {0}, dis[MAX_VEX_NUM] = {0};
VertexType va, vb;

PQunue initQueue()
{
    PQunue pqueue = (PQunue)malloc(sizeof(Queue));
    PQNode pqnode = (PQNode)malloc(sizeof(QNode));
    if (pqnode == NULL)
    {
        printf("队列头空间申请失败！\\n");
        exit(-1);
    }
    pqueue->front = pqueue->rear = pqnode;
    pqnode->qnext = NULL;
    return pqueue;
}

void enQueue(PQunue pqueue, int data)
{
    PQNode pqnode = (PQNode)malloc(sizeof(QNode));
    if (pqnode == NULL)
    {
        printf("队列节点申请失败\n");
        exit(-1);
    }
    pqnode->data = data;
    pqnode->qnext = NULL;
    pqueue->rear->qnext = pqnode;
    pqueue->rear = pqnode;
}

bool isEmpty(PQunue pqueue)
{
    if (pqueue->front == pqueue->rear)
    {
        return true;
    }
    return false;
}

int deQueue(PQunue pqueue)
{
    if (isEmpty(pqueue))
    {
        printf("队列为空\n");
        exit(-1);
    }
    PQNode pqnode = pqueue->front->qnext;
    pqueue->front->qnext = pqnode->qnext;
    if (pqnode == pqueue->rear)
    {
        pqueue->rear = pqueue->front;
    }
    int data = pqnode->data;
    free(pqnode);
    return data;
}

int Locatevax(MGraph G, VertexType u)
{
    for (int i = 0; i < G.vexnum; ++i)
    {
        if (strcmp(u, G.vexs[i]) == 0)
        {
            return i;
        }
    }
    return -1;
}

void init(MGraph &G)
{
    printf("请输入有向图的顶点数，弧数，弧是否含有其他信息(是:1,否:0):\n");
    scanf("%d%d%d", &G.vexnum, &G.arcnum, &IncInfo);
    printf("请输入%d个顶点的值(<%d个字符):\n", G.vexnum, MAX_NAME);
    for (i = 0;i < G.vexnum;i++)
    {
        scanf("%s", &G.vexs[i]);
    }
    for (i = 0;i < G.vexnum;i++)
    {
        for (j = 0;j < G.vexnum;j++)
        {
            G.arcs[i][j].adj = INF;
            G.arcs[i][j].info = NULL;
        }
    }
}

void CreateDG(MGraph &G)
{
    printf("请输入%d条弧的弧尾 弧头(以空格作为间隔):\n", G.arcnum);
    for (k = 0;k < G.arcnum;k++)
    {
        scanf("%s%s", va, vb);
        getchar();
        i = Locatevax(G, va);
        j = Locatevax(G, vb);
        G.arcs[i][j].adj = 1;
        if (IncInfo)
        {
            printf("请输入该弧的相关信息(<%d个字符):\n", MAX_INFO);
            scanf("%s", s);
            l = strlen(s);
            if (l)
            {
                info = (char*)malloc((l + 1) * sizeof(char));
                strcpy(info, s);
                G.arcs[i][j].info = info;
            }
        }
    }
    G.kind = 0;
}

void CreateDN(MGraph &G)
{
    printf("请输入%d条弧的弧尾 弧头 权值(以空格作为间隔):\n", G.arcnum);
    for (k = 0;k < G.arcnum;k++)
    {
        scanf("%s%s%d", va, vb, &w);
        i = Locatevax(G, va);
        j = Locatevax(G, vb);
        G.arcs[i][j].adj = w;
        if (IncInfo)
        {
            printf("请输入该弧的相关信息(<%d个字符):", MAX_INFO);
            scanf("%s", s);
            w = strlen(s);
            if (w)
            {
                info = (char*)malloc((w + 1)*sizeof(char));
                strcpy(info, s);
                G.arcs[i][j].info = info;
            }
        }
    }
    G.kind = 1;
}

void CreateUDG(MGraph &G)
{
    printf("请输入%d条边的顶点1 顶点2(以空格作为间隔):\n", G.arcnum);
    for (k = 0;k < G.arcnum;k++)
    {
        scanf("%s%s", va, vb);
        getchar();
        i = Locatevax(G, va);
        j = Locatevax(G, vb);
        G.arcs[i][j].adj = G.arcs[j][i].adj = 1;
        if (IncInfo)
        {
            printf("请输入该边的相关信息(<%d个字符):", MAX_INFO);
            scanf("%s", s);
            l = strlen(s);
            if (l)
            {
                info = (char*)malloc((l + 1) * sizeof (char));
                strcpy(info, s);
                G.arcs[i][j].info = G.arcs[j][j].info = info;
            }
        }
    }
    G.kind = 2;
}

void CreateUDN(MGraph &G)
{
    printf("请输入%d条边的顶点1 顶点2 权值(以空格为间隔):\n", G.arcnum);
    for (k = 0;k < G.arcnum;k++)
    {
        scanf("%s%s%d", va, vb, w);
        i = Locatevax(G, va);
        j = Locatevax(G, vb);
        G.arcs[i][j].adj = G.arcs[j][i].adj = w;
        if (IncInfo)
        {
            printf("请输入该边的相关信息(<%d个字符):", MAX_INFO);
            scanf("%s", s);
            w = strlen(s);
            if (w)
            {
                info = (char*)malloc((w + 1) * sizeof(char));
                strcpy(info, s);
                G.arcs[i][j].info = G.arcs[j][i].info = info;
            }
        }
    }
    G.kind = 3;
}

void Print(MGraph G)
{
    printf("%d个顶点%d条边(弧)\n", G.vexnum, G.arcnum);
    for (i = 0;i < G.vexnum;i++)
    {
        printf("G.vexs[%d]=%s\n", i, G.vexs[i]);
    }
    printf("图的邻接矩阵:\n");
    for (i = 0;i < G.vexnum;i++)
    {
        for (j = 0;j < G.vexnum;j++)
        {
            if (G.arcs[i][j].adj == INF)
            {
                printf("  INF ");
            }
            else
            {
                printf("  %d ", G.arcs[i][j].adj);
            }
            printf("\n");
        }
    }
    printf("图的信息\n");
    printf("顶点1(弧尾) 顶点2(弧头) 该信息为：\n");
    if (G.kind < 2)
    {
        for (i = 0;i < G.vexnum;i++)
        {
            for(j = 0;j < G.vexnum;j++)
            {
                if (G.arcs[i][j].info)
                {
                    printf("%5s %11s %s\n", G.vexs[i], G.vexs[j], G.arcs[i][j].info);
                }
            }
        }
    }
    else
    {
        for (i = 0;i < G.vexnum;i++)
        {
            for (j = i + 1;j < G.vexnum;j++)
            {
                if (G.arcs[i][j].info)
                {
                    printf("%5s %11s %s\n", G.vexs[i], G.vexs[j], G.arcs[i][j].info);
                }
            }
        }
    }
}

void CreateGraph(MGraph &G)
{
    printf("请输入G的类型(有向图:0,有向网:1,无向图:2,无向网:3):\n");
    scanf("%d", &G.kind);
    if (G.kind == 0)
    {
        init(G);
        CreateDG(G);
    }
    else if (G.kind == 1)
    {
        init(G);
        CreateDN(G);
    }
    else if (G.kind == 2)
    {
        init(G);
        CreateUDG(G);
    }
    else if (G.kind == 3)
    {
        init(G);
        CreateUDN(G);
    }
    else return;
}

void DFS(MGraph G, int v)
{
    printf("%s\n", G.vexs[i]);
    dis[i] = 1;
    for (i = 0;i < G.vexnum;i++)
    {
        if (!dis[i] && G.arcs[i][v].adj != INF)
        {
            DFS(G, i);
        }
    }
}

int First(MGraph &G, int v)
{
    for (i = 0;i < G.vexnum;i++)
    {
        if (G.arcs[v][i].adj != 0 && G.arcs[v][i].adj != INF && !vis[i])
        {
            return i;
        }
    }
    return -1;
}

int Next(MGraph &G, int v, int w)
{
    for (i = w;i < G.vexnum;i++)
    {
        if (G.arcs[v][i].adj != 0 && G.arcs[v][i].adj != INF && !vis[i])return i;
    }
    return -1;
}

void BFS(MGraph G)
{
    int v;
    printf("广度优先遍历序列：");
    PQunue pqueue = initQueue();
    for (i = 0;i < G.vexnum;i++)
    {
        if (!vis[i])
        {
            vis[i] = 1;
            printf("%s ", G.vexs[i]);
            enQueue(pqueue, i);
            while (!isEmpty(pqueue))
            {
                v = deQueue(pqueue);
                for (w = First(G, v);w >= 0;w = Next(G, v, w))
                {
                    if (!vis[w])
                    {
                        vis[w] = 1;
                        printf("%c ", G.vexs[w]);
                        enQueue(pqueue, w);
                    }
                }
            }
        }
    }
    printf("\n");
}

int main()
{
    MGraph G;
    CreateGraph(G);
    Print(G);
    DFS(G, 0);
    BFS(G);
    return 0;
}
