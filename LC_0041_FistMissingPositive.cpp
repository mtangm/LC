/*
Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.
*/

class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        
        int i=0;
        while (i<n)
        {
            while (A[i] != i+1 && A[i] > 0 && A[i] <=n && A[i]!=A[A[i]-1])
            {
                swap(A[i], A[A[i]-1]);

            }
            i++;
        }
        
        int k;
        for (k=0;k<n;k++)
        {
            if (A[k] != k+1)
            {
                break;
            }
        }
        return k+1;
    }
};
