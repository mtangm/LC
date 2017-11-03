/*
 * Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]

*/

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        
        int value=1;
        for (int i=0;i<n/2;i++)
        {
            generate(res, n, i, value);
        }
        
        // odd number of rows/columns
        if (n%2==1)
        {
            res[n/2][n/2]=value;
        }
        
        return res;
    }
    
    
    // draw an outer square.
    // n doesn't change for each call.
    // currentCircleId : nth of the call for this function, 
    void generate(vector<vector<int>> & M, int n, int currentCircleId, int &currentValue)
    {
        
        int firstRow=currentCircleId;
        int lastRow = n -1 - currentCircleId;
        int firstColumn=currentCircleId;
        int lastColumn= n -1- currentCircleId;
        
        //set top row
        for (int i=firstColumn;i<lastColumn;i++)
        {
            M[firstRow][i]= currentValue++;
        }
        
        // set last column
        for (int i=firstRow;i<lastRow;i++)
        {
            M[i][lastColumn]=currentValue++;
        }
        
        // set bottowm row
        for (int i=lastColumn;i>firstColumn;i--)
        {
            M[lastRow][i]=currentValue++;
        }
        
        //set first column
        for (int i=lastRow;i>firstRow;i--)
        {
            M[i][firstColumn]=currentValue++;
        }
    }
};
