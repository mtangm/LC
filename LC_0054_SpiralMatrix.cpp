/*
 * Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].
*
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> res;
        if (matrix.size()==0)
        {
            return res;
        }
        
        int m = matrix.size();
        int n = matrix[0].size();
       // res.resize(m*n);
        
        for (int i=0;i< min(m,n)/2;i++)
        {
            spiral(matrix, i, res);
        }
        
        if (m <=n && m %2 ==1)
        {
            // add the remind row
            for (int i=m/2;i<n-m/2;i++)
            {
                res.emplace_back(matrix[m/2][i]);
            }
        }
        else if (m>n && n%2==1)
        {
            // add the remind column
            for (int i=n/2;i<m-n/2;i++)
            {
                res.emplace_back(matrix[i][n/2]);
            }
        }
        
        
        return res;
    }
    
    void spiral(vector<vector<int>> &matrix, int level, vector<int>& res)
    {
        int first = level; // first row and first column
        int lastRow = matrix.size() -1 - level; // last row
        int lastCol = matrix[0].size() - 1 - level; // last column
        
        // get top row
        for (int i = first; i < lastCol; i++)
        {
            res.emplace_back(matrix[first][i]);
        }
        
        // get right column
        for (int i = first; i < lastRow; i++)
        {
            res.emplace_back(matrix[i][lastCol]);
        }
        
        // get bottom row
        for (int i = lastCol; i >first;i--)
        {
            res.emplace_back(matrix[lastRow][i]);
        }
        
        // get left column
        for (int i = lastRow;i>first;i--)
        {
            res.emplace_back(matrix[i][first]);    
        }
    }
};
