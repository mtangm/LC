/*
 *
 * Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

For example,
Given [3,2,1,5,6,4] and k = 2, return 5.

Note: 
You may assume k is always valid, 1 = k = array's length.
 *
 */

// my own solution. Performance is good.
// 
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        int start = 0;
        int end = nums.size() - 1;
        
        while (start < end)
        {            
            int n = partition(nums, start, end);
            if (n == k-1) return nums[n];
            if (n < k-1)
            {
                start = n + 1;
            }
            else
            {
                end = n - 1;
            }
        }
        
        return nums[start];
    }
    
    int partition(vector<int>& A, int start, int end)
    {
        int last = start;
        for (int i = start+1; i <= end; i++)
        {
            if (A[i] > A[start])
            {
                std::swap(A[i], A[++last]);
            }
        }
        
        std::swap(A[start], A[last]);
        return last;
    }
};
