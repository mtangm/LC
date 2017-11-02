/*
 *
 * Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 *
 *
 *
 *
 */

class Solution {
public:
    
    
    // my own solution without any web search
    //
    // idea:    sort array first
    //        Array:
    //
    //          i -----> j ----------> k
    //
    //
    int threeSumClosest(vector<int>& nums, int target) {
        int result;
        
        std::sort(nums.begin(), nums.end());
        
        result = nums[0] + nums[1] + nums[nums.size() - 1];
        
        for (int i = 0; i < nums.size() - 2; i++)
        {
            for (int j = i + 1, k = nums.size() - 1; j < k;)
            {               
                int prevDiff = result - target;
                if (prevDiff == 0)
                {
                    return target;
                }
                
                int current = nums[i] + nums[j] + nums[k];
                int currentDiff = current - target;
                if (abs(currentDiff) <= abs(prevDiff))
                {
                    result = current;
                }
                
                currentDiff > 0 ? k-- : j++;
            }
        }
        
        return result;
    }
};
