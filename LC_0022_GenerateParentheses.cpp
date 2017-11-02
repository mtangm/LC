/*
 *
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> r;
        string tmp("");
        
        generate(n, 0, 0, tmp, r);
        return r;
    }
    
    
    // lnum: number of left parenthsises in string tmp
    // rnum: number of right parenthsises in string tmp
    // res: current result
    //
    void generate(int n, int lnum, int rnum, string tmp, vector<string>& res)
    {
        if (n==0)
        {
            return;
        }
        
        if (lnum == n)
        {
            for (int i=0;i<n-rnum;i++)
            {
                tmp += ")";
            }
            res.push_back(tmp);
            return;
        }
        
        if (lnum == rnum)
        {
            // can only add left parenthesis
            generate(n, lnum+1, rnum, tmp+"(", res);
        }
        else if (lnum > rnum)
        {
            generate(n, lnum+1, rnum, tmp+"(", res);
            generate(n, lnum, rnum+1, tmp+")", res);
        }
    }
};
