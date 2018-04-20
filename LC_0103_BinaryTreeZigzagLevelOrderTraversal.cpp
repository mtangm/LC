/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
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
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> result;
		stack<TreeNode *> S0;
		stack<TreeNode *> S1;
		S0.push(root);

		int level = 0;
		while (!S0.empty() || !S1.empty())
		{
			vector<int> levelResult;
			stack<TreeNode *>& SCurrent = (level & 0x1) == 0 ? S0 : S1;
			stack<TreeNode *>& SNext = (level & 0x1) == 0 ? S1 : S0;
			int count = SCurrent.size();
			for (int i = 0; i < count; i++)
			{
				TreeNode* n = SCurrent.top();
				SCurrent.pop();
				if (n == NULL)
				{
					continue;
				}

				levelResult.emplace_back(n->val);

				if ((level & 0x1) == 1)
				{
					SNext.push(n->right);
					SNext.push(n->left);
				}
				else
				{
					SNext.push(n->left);
					SNext.push(n->right);
				}
			}

			if (levelResult.size() > 0)
			{
				result.emplace_back(levelResult);
			}

			level++;
		}

		return result;
	}
};
