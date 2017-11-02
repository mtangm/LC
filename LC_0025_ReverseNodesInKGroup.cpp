/*
 * Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL) return NULL;        
        ListNode* pk = head;
        
        // check if the current group has at least K nodes. Also find the tail of the K nodes.
        int i = 1;
        while (i < k && pk->next != NULL)
        {
            i++;
            pk = pk->next;
        }
        
        if (i!=k)
        {
            return head;
        }
        
        ListNode* newHead = pk; // the new head for the current group
        ListNode* pNextHead = pk->next; // head for the next group
        
        // reverse from head to pk        
        int count = 0;
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;
        while (curr != NULL && count < k)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        
        // reverse the next group
        pNextHead = reverseKGroup(pNextHead, k);
        
        // head is the current group's tail, link to the next group
        head->next = pNextHead;
        return newHead;
    }
};
