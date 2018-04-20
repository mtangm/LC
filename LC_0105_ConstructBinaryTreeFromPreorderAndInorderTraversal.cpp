/*
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7
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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.size() == 0 || inorder.size()==0)
        {
            return NULL;
        }
        
        return build(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
    }
    
    TreeNode *build(vector<int>&preorder, int start1, int end1, vector<int>&inorder, int start2, int end2)
    {
        if (start1>end1)
        {
            return NULL;
        }
        
        TreeNode *root = new TreeNode(preorder[start1]);
        
        /*
        if (start1==end1)
        {
            return root;
        }*/
        
        vector<int>::iterator it = std::find(inorder.begin()+start2,
        inorder.begin()+end2, 
        preorder[start1]);
        
        // elements in the left side
        int count=it-inorder.begin()-start2;
        
        root->left=build(preorder, start1+1, start1+count, inorder, start2, start2+count-1);
        root->right=build(preorder, start1+count+1, end1, inorder, start2+count+1, end2);
    }
};
