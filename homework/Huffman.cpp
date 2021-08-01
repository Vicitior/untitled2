#include <stdio.h>
#inclide <iostream>
using namespace std;

typedef struct{
    int weight;
    int parent, lchild, rchild;
}HTNode, *HuffmanTree;
typedef char * * HuffmanCode;
