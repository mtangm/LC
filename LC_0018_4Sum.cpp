/*
 *
 * Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note: The solution set must not contain duplicate quadruplets.

For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
 *
 *
 *
 *
 */


// my own solution, refered my 3sum solution
//

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		std::sort(nums.begin(), nums.end());
		auto results = nSum(nums, 0, 4, target);
		return results;
	}

	vector<vector<int>> nSum(vector<int>&nums, int startIndex, int n, int target)
	{
		vector<vector<int>> results;
		if (startIndex + n > nums.size())
		{
			return results;
		}

		if (n == 2)
		{
			int i = startIndex;
			int j = nums.size() - 1;
			while (i < j)
			{
				int sum = nums[i] + nums[j];
				if (sum == target)
				{
					results.emplace_back(vector<int>{nums[i], nums[j]});
					i++;
					j--;

					//avoid duplicates
					while (i < j && nums[i] == nums[i - 1]) i++;
					while (i < j && nums[j] == nums[j + 1]) j--;
				}
				else if (sum < target)
				{
					i++;
				}
				else
				{
					j--;
				}
			}

			return results;
		}

		for (int k = startIndex; k <= nums.size() - n; k++)
		{
            if (k>startIndex && nums[k] == nums[k-1])
            {
                continue;
            }
			int x = nums[k];
			vector<vector<int>> tmpResults = nSum(nums, k + 1, n - 1, target - x);
			for (auto& v : tmpResults)
			{
				vector<int> r;
				r.emplace_back(x);
				for (auto y : v)
				{
					r.emplace_back(y);
				}
				results.emplace_back(r);
			}
		}

		return results;
	}
};
