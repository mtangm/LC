/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]

*/

//
// My own solution. with a few debugs in VS.
// The tricky part is to use a set to record the values that have been
// swapped with the current value, so that we don't need to swap for the
// same value that exists after the current one.
//
class Solution {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<vector<int>> results;
		permute(nums, 0, results);
		return results;
	}

	void permute(vector<int>&nums, int start, vector<vector<int>>& results)
	{
		if (start == nums.size() - 1)
		{
			results.emplace_back(nums);
			return;
		}

        unordered_set<int> used;
		for (int i = start; i < nums.size(); i++)
		{
			if (used.count(nums[i]) > 0)
            {
                continue;        
            }
            
            used.insert(nums[i]);
			std::swap(nums[start], nums[i]);
			permute(nums, start + 1, results);
			std::swap(nums[start], nums[i]);
		}
	}
};
