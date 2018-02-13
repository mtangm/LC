/*
Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
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
    vector<TreeNode*> generateTrees(int n) {
        
        vector<TreeNode*> result;
        
        result = gen(1, n);
        return result;
    }
    
    vector<TreeNode*> gen(int s, int e)
    {
        vector<TreeNode*> r;
        if (s>e)
        {
            r.push_back(NULL);
            return r;
        }
        
        if (s==e)
        {
            r.emplace_back(new TreeNode(s));
            return r;
        }
        
        for (int i=s;i<=e;i++)
        {
            vector<TreeNode*> lefts = gen(s,i-1);
            vector<TreeNode*> rights = gen(i+1, e);
            
            for (int j=0;j<lefts.size();j++)
            {
                for (int k=0;k<rights.size();k++)
                {
                    TreeNode* n = new TreeNode(i);
                    n->left=lefts[j];
                    n->right=rights[k];
                    r.push_back(n);
                }
            }
        }
        
        return r;
    }
};
