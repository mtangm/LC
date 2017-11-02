/*
 *
 * Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.
 *
 *
 */


class Solution {
public:
    vector<string> letterCombinations(string digits) {
        static const char *padmap[] = {" ", " ", "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        
        vector<string> res;
        
        if (digits.size()==0)
        {
            res.push_back("");
            return res;
        }
        
        vector<string> preRes=letterCombinations(digits.substr(0, digits.size()-1));
        
        // get the possible chars for the last digit
        const char *plast=padmap[digits[digits.size()-1]-'0'];
        
        while (*plast!='\0')
        {
            for (int i=0;i<preRes.size();i++)
            {
                
                res.push_back(preRes[i]+ *plast);
            }
            
            plast++;
        }
        
        return res;
    }
};
