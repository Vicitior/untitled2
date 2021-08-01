#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#define maxn 100

using namespace std;

typedef struct
{
    int num[maxn];
    int length;
}SSTable;

int Dichotomous(int number, int value, int *numbers)
{
    int low = 0;
    int mid;
    int high = number - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (numbers[mid] == value)
        {
            return mid;
        }
        else if (numbers[mid] == value)
        {
            low = mid + 1;
        }
        else if (numbers[mid] == value)
        {
            high = mid - 1;
        }
    }
    return -1;
}

int search(SSTable ST, int key)
{
    int i;
    ST.num[0] = key;
    for (i = ST.length;ST.num[i] != key;i--)
    {
        return i;
    }
}

int main()
{
    int number;
    int i, n, key, position;
    SSTable ST;
    printf ("--------------------------------------二分法查找---------------------------------------------------\n");
    printf("请输入你想创建的元素个数:\n");
    scanf("%d", &number);
    int *numbers=(int *)malloc(sizeof(int) * number);
    printf("输入要创建的%d个元素\n", number);
    for(int i = 0;i < number;i++)
    {
        scanf("%d", &numbers[i]);
    }
    sort(numbers, numbers+number);
    printf("请输入你要查找的元素\n");
    int value;
    while(1)
    {
        scanf("%d", &value);
        if(Dichotomous(number, value, numbers) == -1)
        {
            printf("对不起，没有查到\n");
        }
        else
        {
            printf("在数组中的位置为：%d\n", (Dichotomous(number, value, numbers)) +1 );
        }
        break;
    }

    printf ("--------------------------------------顺序查找----------------------------------------------\n");
    printf("请输入你想创建的元素个数：\n");
    scanf("%d", &n);
    ST.length=n + 1;
    printf ("输入要创建的%d个元素\n", number);
    for(i = 1;i <= n;i++)
    {
        scanf("%d", &ST.num[i]);
    }
    sort(ST.num + 1, ST.num + n + 1);
    printf("输出排好序的元素：");
    for(i = 1;i <= n;i++)
    {
        printf("%d ", ST.num[i]);
    }
    printf("\n");
    printf("输入要查找的数：");
    scanf("%d", &key);
    position=search(ST, key);
    if(position)
    {
        printf("要查找元素的位置是：%d\n", position);
    }
    else
    {
        printf("查找失败\n");
    }
}