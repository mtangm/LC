/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3

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
    bool isSymmetric(TreeNode *root) {
        if (!root)
        {
            return true;
        }
    
        return isSymetricTrees(root->left, root->right);

    }
    
    bool isSymetricTrees(TreeNode *lroot, TreeNode *rroot)
    {
        if (!lroot && !rroot)
        {
            return true;
        }
        
        if (!lroot && rroot || lroot && !rroot)
        {
            return false;
        }
        
        return (lroot->val == rroot->val) &&
                isSymetricTrees(lroot->left, rroot->right) &&
                isSymetricTrees(lroot->right, rroot->left);
    }
};
