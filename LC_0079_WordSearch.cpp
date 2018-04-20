/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
*/

class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        if (board.size()==0 || board[0].size()==0) return false;
        if (word.length()==0) return true;
        
        vector<vector<bool>> used(board.size(),vector<bool>(board[0].size(), false));
        
        for (int i=0;i<board.size();i++)
        {
            for (int j=0;j<board[0].size();j++)
            {
                if (search(board, word,0,i,j,used))
                {
                    return true;
                }
            }
        }
        
        return false;
    }
    
    // m,n: board position to start next search
    // start: string next char pos
    bool search(vector<vector<char>> &board, string word, int start, int m, int n, vector<vector<bool>> &used)
    {
        if (start==word.length())
        {
            return true;
        }
        
        if (m<0 || m>=board.size() || n<0 || n>=board[0].size() || board[m][n]!=word[start] || used[m][n])
        {
            return false;
        }
        
        used[m][n] = true;
        
        if (search(board, word, start+1, m+1,n,used) ||
                search(board, word, start+1, m-1,n,used) ||
                search(board, word, start+1, m,n+1,used) ||
                search(board, word, start+1, m,n-1,used))
        {
            return true;
        }
        
        used[m][n]= false;
        return false;
        
    }
};
