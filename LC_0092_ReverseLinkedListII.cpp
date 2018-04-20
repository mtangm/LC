/*
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 = m = n = length of list.
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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        
        //
        // [head ... tailFront] [headM ....] [headN .... NULL]
        //
        
        ListNode *tailFront = NULL;
        ListNode *headM = NULL;
        ListNode *headN = NULL;
        
        ListNode *p = head;
        
        // assert(m<=n && n <= length
        for (int i=1;i<=n;i++)
        {
            if (i == m-1)
            {
                tailFront=p;
            }
            else if (i==m)
            {
                headM = p;
            }
            p=p->next;
        }
        headN=p;
        
        // reverse [m..n]
        ListNode *newHeadM = reverse(headM, headN);
        
        if (tailFront)
        {
            tailFront->next = newHeadM;
        }
        else
        {
            // no 1st part of sub-list
            head = newHeadM;
        }
        
        headM->next = headN;
        
        return head;
    }
    
    ListNode *reverse(ListNode *head, ListNode *tail)
    {
        ListNode *pre=NULL, *curr = head, *next=NULL;
        
        if (!head)
        {
            return NULL;
        }
        
        while (curr != tail)
        {
            next = curr->next;
            curr->next = pre;
            
            pre = curr;
            curr = next;
        }
        
        return pre;
    }
};
