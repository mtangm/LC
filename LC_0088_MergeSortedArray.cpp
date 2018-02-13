/*
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. The number of elements initialized in nums1 and nums2 are m and n respectively.
*/

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int *C;
        int i, j, k;
        
        C = (int *)malloc(sizeof(int) * (m + n));
        
        for (i = 0, j = 0, k = 0; i < m && j < n; k++)
        {
            if (A[i] < B[j])
            {
                C[k] = A[i];
                i++;
            }
            else
            {
                C[k] = B[j];
                j++;
            }
        }
        
        while (i < m)
        {
            C[k++] = A[i++];
        }
        
        while (j < n)
        {
            C[k++] = B[j++];
        }
        
        memcpy(A, C, sizeof(int) * (m + n));
        free(C);
    }
};
