/*
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree [1,null,2,3],
   1
    \
     2
    /
   3
return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?
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
    vector<int> inorderTraversal(TreeNode *root) {
        stack<TreeNode*> ps;
        vector<int> result;
        
        TreeNode* n = root;
        
        while (!ps.empty() || n != NULL)
        {
            if (n != NULL)
            {
                ps.push(n);
                n = n->left;
            }
            else
            {
                n = ps.top();
                ps.pop();
                
                result.push_back(n->val);
                
                n = n->right;
            }
        }
        
        return result;
    }
};
