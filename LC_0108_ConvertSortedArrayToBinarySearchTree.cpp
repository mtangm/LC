/*
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.


Example:

Given the sorted array: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5

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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return toBST(num, 0, num.size() - 1);
    }
    
    TreeNode *toBST(vector<int> &num, int from, int to)
    {
        if (from > to)
        {
            return NULL;    
        }
        
        int m = (from+to)/2;
        
        TreeNode *newNode = new TreeNode(num[m]);
        
        newNode->left = toBST(num, from, m - 1);
        newNode->right = toBST(num, m + 1, to);
        
        return newNode;
    }
};
