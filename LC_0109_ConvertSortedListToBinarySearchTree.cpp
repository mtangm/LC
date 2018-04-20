/*
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.


Example:

Given the sorted linked list: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5

 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        int n = 0;
        ListNode *p = NULL;
        for (p = head, n = 0; p != NULL; p = p->next, n++)
            ;
            
        return sortedListToBST(head, 0, n -1);
        
        if (head == NULL)
            return NULL;
        

        ListNode *m = findMiddleNode(head, NULL);
        
        TreeNode *root = new TreeNode(m->val);
        
        // get right BST
        TreeNode *right = sortedListToBST(m->next);
        
        root->right = right;
        
        // get left BST
        if (m != head)
        {
            m->next = NULL;
            TreeNode *left = sortedListToBST(head);
            
            root->left = left;
        }
        
        
        return root;
    }
    
    ListNode *findMiddleNode(ListNode *head, ListNode *tail)
    {
        if (head == NULL)
            return NULL;
        
        if (head->next == NULL)
            return head;
            
        ListNode *p, *q;
        
        for (p = head, q = head->next; ;p = p->next, q = q->next->next)
        {
            if (q->next == tail)
                return p;
            
            if (q->next->next == tail)
                return p->next;
        }
        
    }
    
    TreeNode* sortedListToBST(ListNode *& list, int start, int end) {
  if (start > end) return NULL;
  // same as (start+end)/2, avoids overflow
  int mid = start + (end - start) / 2;
  TreeNode *leftChild = sortedListToBST(list, start, mid-1);
  TreeNode *parent = new TreeNode(list->val);
  parent->left = leftChild;
  list = list->next;
  parent->right = sortedListToBST(list, mid+1, end);
  return parent;
}

};
