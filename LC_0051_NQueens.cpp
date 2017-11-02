/*
 * The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
 *
 * Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
*/

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<int> QPositions(n, -1);
        vector<vector<string>> results;
        
        search(n, 0, QPositions, results);
        
        return results;
    }
    
    vector<string> positionsToMatrix(int n, const vector<int>& QPositions)
    {
        vector<string> results(n);
        for (int r = 0; r < n; r++)
        {
            int colum = QPositions[r];
            for (int c = 0; c < n; c++)
            {
                if (c == colum)
                {
                    results[r].append("Q");
                }
                else
                {
                    results[r].append(".");
                }
            }
        }
        
        return results;
    }
    
    void search(int n, int r, vector<int>& QPositions, vector<vector<string>>& results)
    {
        if (r == n)
        {
            // return result
            results.emplace_back(positionsToMatrix(n, QPositions));
            return;
        }
        
        for (int i = 0; i < n; i++)
        {
            if (canPlace(r, i, QPositions))
            {
                QPositions[r] = i;
                search(n, r + 1, QPositions, results);
                QPositions[r] = -1; // backtrace
            }
        }
    }
    
    // check if can place Q at [r,c], assume that rows < r have been placed
    bool canPlace(int r, int c, const vector<int>& QPositions)
    {
        // check vertically
        auto it = std::find(QPositions.begin(), QPositions.end(), c);
        if (it != QPositions.end())
        {
            return false;
        }
        
        // check x
        for (int i = 1; r - i >=0; i++)
        {
            if (QPositions[r-i] >= 0 && (QPositions[r-i] == c - i || QPositions[r-i] == c + i))
            {
                return false;
            }
        }
        
        return true;
    }
};
