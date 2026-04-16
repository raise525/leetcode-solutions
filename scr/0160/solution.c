#include <stdio.h>
#include <stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB){
    struct ListNode *a = headA, *b = headB;
    while (a != b) {
        a = a ? a->next : headB;  //如果a不为NULL，则a指向下一个节点；如果a为NULL，则a指向headB
        b = b ? b->next : headA;
    }
    return a;
}

// struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB){

//     if (headA == NULL || headB == NULL)
//         return NULL;

//     struct ListNode *a = headA;
//     struct ListNode *b = headB;

//     while (a != b) {
//         if(a)
//             a = a->next;
//         else
//             a = headB;
//         if(b)
//             b = b->next;
//         else
//             b = headA;
//     }

//     return a;  // a和b相等时，返回交点；如果没有交点，最终会同时为NULL
// }

int main() {
    // 创建测试链表
    struct ListNode *headA = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *headB = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *intersection = (struct ListNode *)malloc(sizeof(struct ListNode));

    headA->val = 1;
    headA->next = intersection;

    headB->val = 2;
    headB->next = intersection;

    intersection->val = 3;
    intersection->next = NULL;

    // 测试函数
    struct ListNode *result = getIntersectionNode(headA, headB);
    if (result != NULL) {
        printf("Intersection at node with value: %d\n", result->val);
    } else {
        printf("No intersection.\n");
    }

    // 释放内存
    free(headA);
    free(headB);
    free(intersection);

    return 0;
}