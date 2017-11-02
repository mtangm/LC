/*
 *Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note: The solution set must not contain duplicate triplets.

For example, given array S = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
 *
 *
 *
 */


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        
        if (nums.size() < 3) return result;
        
        std::sort(nums.begin(), nums.end());
        
        for (size_t i=0; i < nums.size() - 2; i++)
        {
            size_t j = i+1;
            size_t k = nums.size() - 1;
            while (j < k)
            {
                int x = nums[i] + nums[j] + nums[k];
                if (x == 0)
                {
                    result.emplace_back(vector<int> {nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    
                    // avoid duplicates
                    while (j<k && nums[j]==nums[j-1]) j++;
                    while (j<k && nums[k]==nums[k+1]) k--;
                }
                else if (x > 0)
                {
                    k--;
                }
                else
                {
                    j++;
                }
            }
            
            // avoid duplicates
            while (i<nums.size() - 2 && nums[i+1]==nums[i]) i++;
        }
        
        return result;
    }
};
