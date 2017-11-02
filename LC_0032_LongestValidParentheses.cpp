/*
 *
 * Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
 *
 *
 */

// 
// My solution without referring resources :-)
//
//
class Solution {
public:
    int longestValidParentheses(string s) {
       
        stack<int> S; // keep the index of char in S.
        
        // flag if the corresponding char in s is a part of valid parentheses pair
        //
        vector<bool> isValid;
        isValid.resize(s.size(), false);
            
        // Step 1: construct isValid vector        
        for (int i = 0; i < s.size(); i++)
        {
            if (S.empty())
            {
                S.push(i);
                continue;
            }            
            
            char t = s[S.top()];
            if (t == '(' && s[i] == ')')
            {
                isValid[S.top()] = true;
                isValid[i] = true;
                S.pop();
            }
            else
            {
                S.push(i);
            }            
        }
        
        // Step 2:
        // count the continous valid char from isValid vector.
        // e.g.:    )()()((())(
        //  isValid fttttfttttf
        
        int maxLen = 0;
        int currentLen = 0;
        
        for (int i = 0; i < s.size(); i++)
        {
            if (isValid[i])
            {
                currentLen++;
            }
            else
            {
                currentLen = 0;
            }
            
            maxLen = std::max(maxLen, currentLen);
        }
        
        return maxLen;
    }
};
