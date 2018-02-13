/*
Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]
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
typedef vector<int>::iterator VI;

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    return build(inorder, inorder.begin(), inorder.end(), postorder, postorder.begin(), postorder.end());
}

TreeNode *build(vector<int> &inorder, VI istart, VI iend, vector<int> &postorder, VI pstart, VI pend)
{
    if (istart==iend || pstart==pend)
    {
        return NULL;
    }

    TreeNode *root = new TreeNode(*(pend-1));

    VI it;
    it = std::find(istart, iend, *(pend -1));

    int leftPosition = it - istart;

    root->left = build(inorder, istart, it, postorder, pstart, pstart+leftPosition);
    root->right = build(inorder, it+1, iend, postorder, pstart+leftPosition, pend-1);
    
    return root;
}

};
