#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *mergeTwoLists(struct ListNode *list1, struct ListNode *list2)
{
    // 使用哑节点
    struct ListNode dummy;
    struct ListNode *prev = &dummy;
    dummy.next = NULL;
    
    while (list1 != NULL && list2 != NULL)
    {
        if (list1->val <= list2->val)
        {
            prev->next = list1;
            list1 = list1->next;
        }
        else
        {
            prev->next = list2;
            list2 = list2->next;
        }
        prev = prev->next;
    }
    
    // 连接剩余部分
    prev->next = (list1 != NULL) ? list1 : list2;
    
    return dummy.next;  // 返回真正的头节点
}