/*
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]
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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        queue<TreeNode*> dfs;
        queue<int> levels;
        
        vector<int> nodes;
        vector<int> vlevels;
        
        vector<vector<int> > result;
        
        if (root == NULL)
        {
            return result;
        }
        
        dfs.push(root);
        levels.push(0);
        while (!dfs.empty())
        {
            TreeNode *node = dfs.front();
            int currlevel = levels.front();
            
            dfs.pop();
            levels.pop();
            
            nodes.push_back(node->val);
            vlevels.push_back(currlevel);
            
            if (node->left)
            {
                dfs.push(node->left);
                levels.push(currlevel + 1);
            }
            
            if (node->right)
            {
                dfs.push(node->right);
                levels.push(currlevel + 1);
            }
        }
        
        for (int i = nodes.size() - 1; i >= 0;)
        {
            vector<int> onelevelnodes;
            
            int start = i;
            while (start > 1 && vlevels[start - 1] == vlevels[i])
            {
                start--;
            }
            
            for (int j = start; j <= i; j++)
            {
                onelevelnodes.push_back(nodes[j]);
            }
            result.push_back(onelevelnodes);
            
            i = start - 1;
        }
        
        return result;
    }
};
