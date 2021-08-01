#include <malloc.h>
#include <stdio.h>
#include <iostream>
#define MAXSIZE 20
#define EQ(a, b) ((a) == (b))
#define LT(a, b) ((a) < (b))
#define LQ(a, b) ((a) > (b))

using namespace std;
typedef int KeyType;

typedef struct
{
    KeyType key;
}RedType;

typedef struct
{
    RedType r[MAXSIZE + 1];
    int length;
}SqList;

void InsertSort(SqList &L)
{
    int i, j;
    for (i = 2;i < L.length;i++)
    {
     if (LT(L.r[i].key,L.r[i - 1].key))
     {
         L.r[0].key = L.r[i].key;
         for (j = i - 1; LT(L.r[0].key, L.r[j].key);j--)
         {
             L.r[j + 1].key = L.r[j].key;
         }
         L.r[j + 1].key = L.r[0].key;
     }
    }
}

int Partition(SqList &L, int low, int high)
{
    L.r[0].key = L.r[low].key;
    int pivotkey = L.r[low].key;
    while (low < high)
    {
        while (low < high && L.r[high].key >= pivotkey)
        {
            high--;
        }
        L.r[low].key = L.r[high].key;
        while (low < high && L.r[high].key <= pivotkey)
        {
            low++;
        }
        L.r[high].key = L.r[low].key;
    }
    L.r[low].key = L.r[0].key;
    return low;
}

void QSort(SqList &L, int low, int high)
{
    int pivotloc;
    if (low < high)
    {
        pivotloc = Partition(L, low, high);
        QSort(L, low, pivotloc - 1);
        QSort(L, pivotloc + 1, high);
    }
}

void QuickSort(SqList &L)
{
    QSort(L, 1, L.length);
}

void Merge(RedType *SR, RedType *TR, int i, int m, int n)
{
    int j, k;
    for(j = m + 1,k = i;i <= m&&j <= n;k++)
    {
        if (LT(SR[i].key,SR[j].key))
        {
            TR[k].key = SR[i++].key;
        }
        else
        {
            TR[k].key = SR[j++].key;
        }
    }
    if (i <= m)
    {
        while (i <= m)
        {
            TR[k++].key = SR[i++].key;
        }
    }
    if(j <= n)
    {
        while(j <= n)
        {
            TR[k++].key = SR[j++].key;
        }
    }
}

void MSort(RedType *SR, RedType *TR1, int s, int t)
{
    int m;
    RedType TR2[100];
    if(s == t)
    {
        TR1[s] = SR[s];
    }
    else
    {
        m = (s+t) / 2;
        MSort(SR, TR2, s, m);
        MSort(SR, TR2, m+1, t);
        Merge(TR2, TR1, s, m, t);
    }
}

void Mergesort(SqList &L)
{
    RedType SR[100];
    for(int i = 1;i <= L.length;i++)
    {
        SR[i].key = L.r[i].key;
    }
    MSort(SR,L.r,1, L.length);
}

int main()
{
    SqList S;
    int number;
    printf ("请输入需要排序的元素个数：\n");
    scanf("%d", &number);
    printf ("请输入要排序的元素：\n");
    for(int i = 1;i <= number;i++)
    {
        scanf("%d", &S.r[i].key);
    }
    S.length = number;
    //直接插入
    printf ("\n直接排序的结果：\n");
    InsertSort(S);
    for(int i = 1;i <= S.length;i++)
    {
        printf("%d ", S.r[i].key);
    }

    //快速排序
    printf ("\n快速排序的结果是：\n");
    QuickSort(S);
    for(int i = 1;i <= S.length;i++)
    {
        printf("%d ", S.r[i].key);
    }

    //归并排序
    printf ("\n归并排序的结果是：\n");
    Mergesort(S);
    for(int i = 1;i <= S.length;i++)
    {
        printf("%d ", S.r[i].key);
    }
}