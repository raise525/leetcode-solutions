#include <stdio.h>
#include <stdlib.h>

// 单链表节点的定义
struct ListNode {
    int val;
    struct ListNode *next;
};

/**
 * 删除链表中的节点（只给定要删除的节点）
 * 参数 node 就是要删除的节点，且该节点不是链表的尾节点
 */
void deleteNode(struct ListNode* node) {
    // 题目保证 node 不是尾节点，所以 node->next 一定不为空
    // 将下一个节点的值复制到当前节点
    node->val = node->next->val;
    // 删除下一个节点
    struct ListNode* temp = node->next;
    node->next = node->next->next;
    // 释放被删除节点的内存（如果是动态分配的）
    free(temp);
}