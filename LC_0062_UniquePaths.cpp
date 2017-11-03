/*
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?
*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> tab(m, vector<int>(n,1));
        
        for (int i=1;i<m;i++)
        {
            for (int j=1;j<n;j++)
            {
                tab[i][j]=tab[i-1][j]+tab[i][j-1];
            }
        }
        
        return tab[m-1][n-1];
    }
};
