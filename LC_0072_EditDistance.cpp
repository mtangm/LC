/*
Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character

*/
class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size();
        int len2 = word2.size();
        
        vector<vector<int>> DP(len1 + 1, vector<int>(len2 + 1, 0));
        
        for (int i = 1; i <= len1; i++)
        {
            DP[i][0] = i;
        }
        
        for (int j = 1; j <= len2; j++)
        {
            DP[0][j] = j;
        }
        
        for (int i = 0; i < len1; i++)
        {
            for (int j = 0; j < len2; j++)
            {
                if (word1[i] == word2[j])
                {
                    DP[i+1][j+1] = DP[i][j];
                }
                else
                {
                    int minD = min(DP[i][j], min(DP[i][j+1], DP[i+1][j]));
                    DP[i+1][j+1] = minD + 1;
                }
            }
        }
        
        return DP[len1][len2];
    }
};
