/*
 *
 * Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note: 
You may assume k is always valid, 1 = k = BST's total elements.

Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?
 *
 *
 */

// my own solution. Performance is good.
//
// For the follow up question above, we can use the 
// Augumented BST, where each node contains the Count field about
// how many nodes are included.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int value;
        int count = 0;
        visit(root, k, count, value);
        return value;
    }
    
    bool visit(TreeNode* n, int k, int& count, int& value)
    {
        if (!n) return false;
        
        if (visit(n->left, k, count, value))
        {
            return true;
        }
        
        if (++count == k)
        {
            value = n->val;
            return true;
        }
        
        return visit(n->right, k, count, value);
    }
};
