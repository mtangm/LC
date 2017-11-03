/*
 * Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
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
    ListNode *rotateRight(ListNode *head, int k) {
        ListNode *pk;
        int num;
        ListNode *p;
        
        if (k==0||!head) 
            return head;
        
        // get list size
        for (num=1, p=head; p->next !=NULL; num++, p=p->next )
            ;
        
        // p now is the tail
        
        // m is the actual position for rotate
        int m = k % num;
        
        if (m==0) return head;
        
        // find the position to rotate
        int i;
        for (i = 0, pk = head; i < num - m -1; pk=pk->next, i++)
            ;
        
        // pk->next will be the new head
        
        // note that p is the tail
        p->next = head;
        head = pk->next;
        pk->next = NULL;
        
        return head;
        
    }
};
