/*
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.

 */

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> M;
        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();
        for (int i = 0; i < rows; i++)
        {
            vector<int> arow(cols, 0);
            M.emplace_back(arow);
        }
        
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (i == 0 && j == 0)
                {
                    M[0][0] = obstacleGrid[0][0] == 0 ? 1 : 0;
                    continue;
                }
                
                if (obstacleGrid[i][j] == 1)
                {
                    M[i][j] = 0;
                    continue;
                }
                
                if (i == 0 && j > 0)
                {
                    M[i][j] = M[i][j-1];
                    continue;
                }
                
                if (j == 0 && i > 0)
                {
                    M[i][j] = M[i-1][j];
                    continue;
                }
                
                M[i][j] = M[i-1][j] + M[i][j-1];
            }
        }
        
        return M[rows - 1][cols - 1];
    }
};
