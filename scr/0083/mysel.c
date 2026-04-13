#include <stdio.h>
#include <stdlib.h>

 struct ListNode {
     int val;
     struct ListNode *next;
 };
 
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if(head == NULL || head->next == NULL){
        return head;
    }

    struct ListNode* prev = head;
    struct ListNode* curr = head->next;

    while(curr != NULL){
        if(prev->val == curr->val){
            prev->next = curr->next;
            free(curr);
        }
        else 
        {
            prev = curr;
        }
        curr = curr->next;
    }
    return head;
}

