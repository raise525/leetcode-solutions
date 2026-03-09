#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode* removeElements(struct ListNode* head, int val) {
    // 创建一个虚拟头结点
    struct ListNode* dummyNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummyNode->val = val - 1;  // 确保虚拟头结点的值不等于要删除的值
    dummyNode->next = head;
    
    struct ListNode* prev = dummyNode;
    
    // 确保当前结点后还有结点
    while (prev->next != NULL) {
        if (prev->next->val == val) {
            struct ListNode* temp = prev->next;  // 临时保存要删除的结点
            prev->next = prev->next->next;       // 跳过要删除的结点
            free(temp);                           // 释放被删除结点的内存
        } else {
            prev = prev->next;
        }
    }
    
    struct ListNode* newHead = dummyNode->next;  // 保存新的头结点
    free(dummyNode);                              // 释放虚拟头结点
    return newHead;
}