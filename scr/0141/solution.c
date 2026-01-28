#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

bool hasCycle(struct ListNode* head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head; // 乌龟和兔子同时从起点出发
    while (fast && fast->next) {
        slow = slow->next; // 乌龟走一步
        fast = fast->next->next; // 兔子走两步
        if (fast == slow) { // 兔子追上乌龟（套圈），说明有环
            return true;
        }
    }
    return false; // 访问到了链表末尾，无环
}

