#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    if (head == NULL || left == right) {
        return head;
    }
    
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* p0 = &dummy;
    for(int i = 1; i < left ; i++) {
        p0 = p0->next;
    }

    struct ListNode* prev = NULL;
    struct ListNode* cur = p0->next;
    for(int i = left; i <= right; i++)
    {
        struct ListNode* next = cur->next;
        cur->next = prev;
        prev = cur;
        cur= next;
    }

    p0->next->next = cur;
    p0->next = prev;
    return dummy.next;

}