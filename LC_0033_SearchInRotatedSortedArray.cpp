/*
 *
 *Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
 *
 */
class Solution {
public:
    int search(int A[], int n, int target) {
        return search(A, 0, n-1, target);
    }
    
    int search(int A[], int lo, int hi, int target)
    {
        if (lo>hi)
        {
            return -1; // not found
        }
        
        if (lo==hi)
        {
            if (A[lo]==target)
            {
                return lo;
            }
            return -1; // not found
        }
        
        int m = lo + (hi-lo)/2;
        
        if (A[m]==target)
        {
            return m;
        }
        
        if (A[m]>target)
        {
            if (A[m]<A[hi])
            {
                // right half is sorted
                return search(A, lo, m-1, target);
            }
            else
            {
                // right half is not sorted
                int x = search(A, lo, m-1, target);
                if (x!=-1) return x;
                return search(A, m+1, hi, target);
            }
        }
        else
        {
            if (A[m]>A[lo])
            {
                // left half is sorted
                return search(A, m+1,hi,target );
            }
            else
            {
                
                int x=search(A, lo, m-1,target );
                if (x!=-1) return x;
                return search(A, m+1, hi, target);
            }
        }
    }
};
