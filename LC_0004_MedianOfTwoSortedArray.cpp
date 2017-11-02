/*
 * submitted 2 years ago.
 * not fast
 */

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int total=m+n;
        if (total&0x1)
        {
            return selectK(A,m,B,n,total/2+1);
        }
        else
        {
            return (selectK(A,m,B,n,total/2)+selectK(A,m,B,n,total/2+1))/2.0;
        }
    }
    
    double selectK(int A[], int m, int B[], int n, int k)
    {
        if (m>n) return selectK(B,n,A,m,k);
        if (m==0) return B[k-1];
        if (k==1) return min(A[0], B[0]);
        
        int ia=min(m, k/2);
        int ib=k-ia;
        
        if (A[ia-1]==B[ib-1])
        {
            return A[ia-1];
        }
        else if (A[ia-1]<B[ib-1])
        {
            // select from 2nd half of A and
            // first half of B
            return selectK(A+ia, m-ia,B,ib,k-ia);
        }
        else
        {
            return selectK(A,ia,B+ib,n-ib,k-ib);
        }
    }
};
