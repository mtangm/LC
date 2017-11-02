/*
 *
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
 *
 *
 *
 */

class Solution {
public:
    bool isValid(string s) {
        stack<char> cstack;
        
        for (int i=0;i<s.size();i++)
        {
            if (s[i]=='{'||s[i]=='['||s[i]=='(')
            {
                cstack.push(s[i]);
            }
            else
            {
                if (cstack.empty())
                {
                    return false;
                }

                char t = cstack.top();
                switch (s[i])
                {
                case '}':
                    if (t !='{') return false;
                    break;
                    
                case ']':
                    if (t!='[') return false;
                    break;
                    
                case ')':
                    if (t!='(') return false;
                    break;
                    
                default:
                    return false;
                }
                                
                cstack.pop();
            }
        }
        
        if (cstack.empty())
        {
            return true;
        }    
        return false;
    }
};
