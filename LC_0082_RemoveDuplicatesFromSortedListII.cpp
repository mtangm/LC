/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.

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
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *prev = head, *curr;
        
        ListNode *s;
        
        ListNode dummy(0);
        
        if (!head) return NULL;
        
        dummy.next = head;
        prev = &dummy;  // prev points to the last checked element that will be kept in the list
        
        s = head;
        curr = head->next;
        bool todel = false;
        while (curr)
        {
            if (curr->val==s->val)
            {
                todel = true;
                curr = curr->next;
            }
            else
            {
                if (todel)
                {
                    // delete from s till (before) curr
                    ListNode *n=NULL;
                    for (ListNode *q = s; q!=curr; q=n)
                    {
                        n = q->next;
                        delete q;
                    }
                    prev->next = curr;
                    todel=false;
                }
                else
                {
                    prev=prev->next;
                }
                s=curr;
                curr=curr->next;
            }
        }
        
        if (todel)
        {
            ListNode *n=NULL;
            for (ListNode *q = s; q!=curr; q=n)
            {
                n = q->next;
                delete q;
            }
            prev->next = curr;
        }
        
        return dummy.next;
    }
};
