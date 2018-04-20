/*
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.

*/

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n<=2) return n;
        
        int delcount=0;
        
        int count=1;
        int last = 0;
        for (int i=1;i<n;i++)
        {
            if (A[i]==A[last])
            {
                if (++count >2)
                {
                    delcount++;
                }
                else
                {
                    A[++last]=A[i];
                }
            }
            else
            {
                A[++last]=A[i];
                count=1;
            }
        }
        
        return n-delcount;
    }
};

