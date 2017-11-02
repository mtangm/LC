/*
 * You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode head(0);
        ListNode *ptail=&head;
        int carry=0;
        
        while (l1 || l2)
        {
            int num= (l1 ? l1->val : 0) + (l2 ? l2->val : 0) +carry;
            ListNode *p=new ListNode(num%10);
            
            carry=num/10;
            
            ptail->next = p;
            ptail=p;
            
            if (l1) l1=l1->next;
            if (l2) l2=l2->next;
        }
        
        if (carry >0)
        {
            ptail->next = new ListNode(carry);
        }
        
        return head.next;
    }
};
