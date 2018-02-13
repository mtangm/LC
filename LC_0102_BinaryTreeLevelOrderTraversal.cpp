/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
*/

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        travel(root, 0, res);
        return res;
    }
    
    void travel(const TreeNode* root, int level, vector<vector<int>>& res)
    {
        if (!root) return;
        
        if (res.size() < level + 1)
        {
            res.emplace_back(vector<int>{root->val});
        }
        else
        {
            res[level].emplace_back(root->val);
        }
        
        travel(root->left, level+1, res);
        travel(root->right, level+1, res);
    }
};
