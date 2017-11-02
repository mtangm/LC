/*
 *
 * Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.
 *
 *
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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        
        // think about the case of {1}, 1. ie. one node, remove it.
        
        ListNode *p, *q, *t; // q is the prev node of the one to be deleted
        
        ListNode dummy(0);
        dummy.next=head;
        
        p=head;
        for (int i=1;i<n;i++)
        {
            p=p->next;
        }
        
        q=&dummy;
        while(p->next!=NULL)
        {
            p=p->next;
            q=q->next;
        }
        
        t=q->next; // t points to the node to be deleted
        q->next=q->next->next;
        delete t;
        
        return dummy.next;
    }
};
