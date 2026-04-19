#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// 链表节点定义
typedef struct MinStackNode {
    int val;
    int min;  // 当前节点及之前的最小值
    struct MinStackNode* next;
} MinStackNode;


//有思路，但是不太会写，加油吧