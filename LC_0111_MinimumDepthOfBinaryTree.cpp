/*
 Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
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
    int minDepth(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        if (!root)
        {
            return 0;
        }
        
        if (root->left == NULL && root->right !=NULL)
        {
            return minDepth(root->right) + 1;
        }
        
        if (root->left != NULL && root->right == NULL)
        {
            return minDepth(root->left) + 1;
        }
        
        int depLeft = minDepth(root->left);
        int depRight = minDepth(root->right);
        
        return min(depLeft, depRight) + 1;

    }
};
