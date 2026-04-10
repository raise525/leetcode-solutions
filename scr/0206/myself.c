#include <stdio.h>  
  
  struct ListNode {
   int val;
    struct ListNode *next;
  };

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* curr;
    struct ListNode* p;
    struct ListNode* q;
    curr = head;    //完全没有考虑边界条件！！！
    p = curr->next;
    q = p->next;

    while(q != NULL){
        p->next = curr;
        curr = p;
        p = q;
        q = q->next;
    }
    return p;
}


struct ListNode* reverseList(struct ListNode* head) {
    // 处理空链表或只有一个节点的情况
    if (head == NULL || head->next == NULL) {
        return head;
    }
    
    struct ListNode* prev = NULL;      // 前一个节点
    struct ListNode* curr = head;      // 当前节点
    struct ListNode* next = NULL;      // 下一个节点
    
    while (curr != NULL) {
        next = curr->next;    // 保存下一个节点
        curr->next = prev;    // 反转指针
        prev = curr;          // 移动 prev
        curr = next;          // 移动 curr
    }
    
    return prev;  // prev 是反转后的新头节点
}