/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
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
    ListNode *partition(ListNode *head, int x) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        ListNode *tail = NULL;
        int num = 0;
        
        // find the tail
        if (head == NULL)
        {
            return NULL;
        }
        
        for (tail = head, num = 1; tail->next != NULL; tail = tail->next, ++num)
            ;
            
        
        ListNode *newtail = tail;
        ListNode *newHead = NULL;
        
        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *next = NULL;
        
        
        for (int i = 0; i < num; i++)
        {
            next = curr->next;
            if (curr->val >= x)
            {
                if (curr != newtail)
                {
                    if (prev)
                    {
                        prev->next = next;
                    }
                    
                    newtail->next = curr;
                    newtail = curr;    
                    curr->next = NULL;
                }
            }
            else
            {
                prev = curr;
                
                // found the first node that is less than x, it will be the new head
                if (newHead == NULL)
                {
                    newHead = curr;
                }
            }
    
            curr = next;

        }
        
        return newHead != NULL ? newHead : head;
    }
};
