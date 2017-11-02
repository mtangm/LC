/*
 *
 *
 *
 *Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> res;

        // do binary search
        int start = 0;
        int end = n - 1;
        
        while (start <= end)
        {
            int m = (start+end)/2;
            
            if (A[m]==target)
            {
                // found target.
                // now search backward and forward to check the range
                
                // search backward
                int i;
                for (i = m; i>=start && A[i]==target; i--)
                    ;
                    
                // search forward
                int j;
                for (j = m; j<=end && A[j]==target; j++)
                    ;
                    
                res.push_back(i+1);
                res.push_back(j-1);
                
                return res;
            }
            else if (A[m] > target)
            {
                end = m -1;
            }
            else 
            {
                start = m +1;
            }
        }
        
        // didn't find target
        res.push_back(-1);
        res.push_back(-1);
        return res;
    }
};
