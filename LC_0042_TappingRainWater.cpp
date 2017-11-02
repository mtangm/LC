/*
 *Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
 */

class Solution {
public:
    //
    // My own solution without search.
    //
    // Idea: for each item x in array, find its left highest bar and its right highest bar. The water that can 
    // be saved for position x will be W=min(xLeftHighest, xRightHighest) - height[x] if W > 0. If W < 0, no
    // water can be saved in position x.
    //
    //
    //   .. .. .. leftTop .. .. x .. .. .. rightTop .. .. ..
    //
    
    int trap(vector<int>& height) {
        int len = height.size();
        if (len == 0)
        {
            return 0;
        }
        
        vector<int> leftTop(len);                
        int leftMax = height[0];
        leftTop[0] = leftMax;
        for (int i = 0; i < len - 1; i++)
        {
            leftMax = std::max(leftMax, height[i]);
            leftTop[i + 1] = leftMax;
        }                

        vector<int> rightTop(len);
        int rightMax = height[len - 1];
        rightTop[len - 1] = rightMax;
        for (int j = len - 1; j > 0; j--)
        {
            rightMax = std::max(rightMax, height[j]);
            rightTop[j - 1] = rightMax;
        }
        
        int sum = 0;
        for (int k = 0; k < len - 1; k++)
        {
            int water = std::min(leftTop[k], rightTop[k]) - height[k];
            sum += water > 0 ? water : 0;
        }
        
        return sum;        
    }
};
