
class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        
        vector<bool> zeroRows(matrix.size(), false);
        vector<bool> zeroCols(matrix[0].size(), false);
        
        for (int i=0; i<matrix.size();i++)
        {
            for (int j=0; j<matrix[0].size();j++)
            {
                if (matrix[i][j] == 0)
                {
                    zeroRows[i] = true;
                    zeroCols[j] = true;
                }
            }
        }
        
        for (int i=0; i<matrix.size();i++)
        {
            for (int j=0; j<matrix[0].size();j++)
            {
                if (zeroRows[i] || zeroCols[j])
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
