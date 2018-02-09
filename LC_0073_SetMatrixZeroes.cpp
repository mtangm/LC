/*
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

click to show follow up.

Follow up:
Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
*/

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        
        vector<pair<int, int> > zeroPoints;
        
        for (int i=0; i<matrix.size();i++)
        {
            for (int j=0; j<matrix[0].size();j++)
            {
                if (matrix[i][j] == 0)
                {
                    zeroPoints.push_back(make_pair(i,j));
                }
            }
        }
        
        for (int k=0; k<zeroPoints.size();k++)
        {
            for (int a=0;a<matrix.size();a++)
            {
                matrix[a][zeroPoints[k].second]=0;
            }
            
            for (int b=0;b<matrix[0].size();b++)
            {
                matrix[zeroPoints[k].first][b]=0;
            }
        }
    }
};
