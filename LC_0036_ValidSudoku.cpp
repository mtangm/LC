/*
 *Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
 *
 */

class Solution {
    //
    // my solution, elegant
    //
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        //check each row
        for (int i=0;i<9;i++)
        {
            if (!valid(board, i, i, 0, 8)) return false;
        }
        
        // each column
        for (int i=0;i<9;i++)
        {
            if (!valid(board, 0, 8, i, i)) return false;
        }
        
        for (int i=0; i<9;i+=3)
        {
            for (int j=0;j<9;j+=3)
            {
                if (!valid(board, i, i+2,j,j+2)) return false;
            }
        }
        
        return true;
    }
    
    bool valid(vector<vector<char>> &board, int sr, int er, int sc, int ec)
    {
        bool tab[9]={false};
        
        for (int i=sr; i<=er; i++)
        {
            for (int j=sc; j<=ec; j++)
            {
                if (board[i][j]=='.') 
                {
                    continue;
                }
                
                int n=board[i][j]-'1';
                if (tab[n])
                {
                    return false;
                }
                tab[n]=true;
            }
        }
        
        return true;
    }
};
