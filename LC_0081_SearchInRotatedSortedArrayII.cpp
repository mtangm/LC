/*
 Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Write a function to determine if a given target is in the array.

The array may contain duplicates.
*/
class Solution {
public:
    bool search(int A[], int n, int target) {
        int x = search(A, 0, n-1, target);
        
        return x==-1 ? false : true;
    }
    
    // my own solution.
    //
    // this is copied from my solution of "Search in Rotated Sorted Array "
    // without any change. That is, this function works for both questions.
    //
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
