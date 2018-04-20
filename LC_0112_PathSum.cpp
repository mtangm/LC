/*
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

For example:
Given the below binary tree and sum = 22,

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
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
    bool hasPathSum(TreeNode *root, int sum) {
        return travel(root, sum, 0);
    }
    
    bool travel(TreeNode *root, int sum, int path)
    {
        bool found = false;
        if (!root)
        {
            return false;
        }
        
        path += root->val;
        
        // post order
        
        if (root->left)
        {
            found = travel(root->left, sum, path);
            if (found)
            {
                return true;
            }
        }
        
        if (root->right)
        {
            found = travel(root->right, sum, path);
            if (found)
            {
                return true;
            }
        }
        
        // leaf
        if (!root->left && !root->right)
        {
            if (path == sum)
            {
                return true;
            }
        }
        
        return false;
    }
};
