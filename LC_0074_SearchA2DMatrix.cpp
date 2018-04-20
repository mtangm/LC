/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int M = matrix.size();
        if (M == 0) return false;
        int N = matrix[0].size();
        
        int start = 0;
        int end = M * N - 1;
        
        while (start <= end)
        {
            int middle = (start+end)/2;
            int mvalue = getValue(matrix, middle);
            if (mvalue == target)
            {
                return true;
            }
            
            if (mvalue < target)
            {
                start = middle + 1;
            }
            else
            {
                end = middle - 1;
            }
        }
        
        return false;
    }
    
    // 
    // index is from [0..M*N-1], where M is the sizeof Row, N is the size of Column
    //
    int getValue(vector<vector<int>> &matrix, int index)
    {
        // assume that index is always in the range
        int M = matrix.size();
        int N = matrix[0].size();
        
        int i = index / N;
        int j = index - i * N;
        
        return matrix[i][j];
    }
};
