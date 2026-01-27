#include <stdlib.h>
#include <string.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *cur = head, *pre = NULL;
    while (cur != NULL) {
        struct ListNode* tmp = cur->next; // 暂存后继节点 cur->next
        cur->next = pre;                 // 修改 next 引用指向
        pre = cur;                       // pre 暂存 cur
        cur = tmp;                       // cur 访问下一节点
    }
    return pre;
}