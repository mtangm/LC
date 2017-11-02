/*
 *
 Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 ? 2
[1,3,5,6], 2 ? 1
[1,3,5,6], 7 ? 4
[1,3,5,6], 0 ? 0
*
* *
*/

class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        if (n == 0)
        {
            return 0;
        }
        
        int low = 0;
        int up = n - 1;
        int m;
        
        while (low <= up)
        {
            m = (low+up)/2;
            if (A[m] == target)
            {
                return m;
            }
            
            if (A[m] > target)
            {
                up = m - 1;
            }
            else if (A[m] < target)
            {
                low = m + 1;
            }
        }
        
        return low;
    }
};
