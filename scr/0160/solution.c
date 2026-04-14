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