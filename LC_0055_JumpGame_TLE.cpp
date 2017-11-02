/*
 *
 *Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.

*/

class Solution {
public:
    bool canJump(int A[], int n) {
        bool *R;
        if (n==0)
        {
            return false;
        }
        
        R = new bool[n];
        
        for (int i=0;i<n;i++)
        {
            R[i]=false;
        }
        
        R[0]=true;
        for (int i =0; i<n;i++)
        {
            for (int k =1; k<=A[i];k++)
            {
                if (i+k<n)
                {
                    R[i+k]=true;
                }
                
                if (i+k==n-1)
                {
                    return true;
                }
            }
        }
        
        for (int i=0;i<n;i++)
        {
            if (!R[i])
            {
                return false;
            }
        }
        return true;
    }
};
