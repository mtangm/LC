/*
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.
*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        if (heights.size() == 0) 
            return 0;
        vector<int> left(heights.size());  // store the index of the first item whose height is less than heights[i] from left
        vector<int> right(heights.size()); // store the index of the first item whose height is less than heights[i] from right
        left[0] = -1;
        right[heights.size()-1] = heights.size();
        
        // calculate left
        for (int i = 1; i < heights.size(); i++)
        {
            int j = i - 1;
            while (j >= 0 && heights[j] >= heights[i])
            {
                j = left[j];
            }
            left[i] = j;
        }
        
        // calculate right
        for (int i = heights.size() - 2; i >= 0; i--)
        {
            int j = i + 1;
            while (j <= heights.size() - 1 && heights[j] >= heights[i])
            {
                j = right[j];
            }
            right[i] = j;
        }
        
        int maxArea = 0;
        for (int i = 0; i < heights.size(); i++)
        {
            maxArea = std::max(maxArea, heights[i] * (right[i] - left[i] - 1));
        }
        
        return maxArea;
    }
};
