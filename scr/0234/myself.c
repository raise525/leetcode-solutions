#include <stdbool.h>
#include <stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};


bool isPalindrome(struct ListNode* head){
    if (head == NULL || head->next == NULL) {
        return true;
    }
    struct ListNode *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    struct ListNode *prev = NULL, *curr = slow, *next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    struct ListNode *p1 = head, *p2 = prev;
    while (p2 != NULL) {
        if (p1->val != p2->val) {
            return false;
        }
        p1 = p1->next;
        p2 = p2->next;
    }
    return true;
}

int main()
{
    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    head->val = 1;
    head->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    head->next->val = 2;
    head->next->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    head->next->next->val = 2;
    head->next->next->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    head->next->next->next->val = 1;
    head->next->next->next->next = NULL;

    bool result = isPalindrome(head);
    if (result) {
        printf("true\n");
    } else {
        printf("false\n");
    }

}
