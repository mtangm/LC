/*
 *
 * Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
 *
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        
        if (l1 ==NULL) return l2;
        
        if (l2==NULL) return l1;
        
        ListNode head(0);
        ListNode *tail = &head;

        while (l1 && l2)
        {
            if (l1->val > l2->val)
            {
                tail->next = l2;
                tail = l2;
                l2 = l2->next;
            }
            else
            {
                tail->next = l1;
                tail = l1;
                l1 = l1->next;
            }
        }
        
        if (l1)
        {
            tail->next = l1;
        }
        else if (l2)
        {
            tail->next = l2;
        }
        
        return head.next;
    }
};
