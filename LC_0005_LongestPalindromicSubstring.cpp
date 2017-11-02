/*
 * Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
 *
 */

class Solution {
public:
    string longestPalindrome(string s) {
        int longest = 0;
        string longestStr;
        
        for (int i=0;i<s.size();i++)
        {
            // use the current char as the center and check palindrom
            string astr=getPalindrom(s, i, true);
            
            if (astr.size()>longest)
            {
                longest=astr.size();
                longestStr=astr;
            }
            
            // use the Virutal Middle of the current char and next char to check palindrom
            if (i<s.size()-1)
            {
                astr=getPalindrom(s,i,false);
                if (astr.size()>longest)
                {
                    longest=astr.size();
                    longestStr=astr;
                }
            }
        }
        
        return longestStr;
    }
    
    
    // x x x x [center] y y y y ----- odd = true
    // x x x x [center] | [center+1] y y y y ---- odd = false
    //
    // if odd==true, check palindrom "xxxxxxx C yyyyyyy"
    // if odd=false, check "xxxxxx C N yyyyyyy"
    //
    string getPalindrom(string str, int center, bool odd)
    {
        string astr("");
        int s;
        int e;
        
        if (odd)
        {
            s=e=center;
        }
        else
        {
            s=center;
            e=center+1;
            if (str[s]!=str[e]) return string(""); // return empty string
        }
        
        while (s>0 && e < str.size()-1)
        {
            if (str[s-1]==str[e+1])
            {
                s--;
                e++;
            }
            else
            {
                break;
            }
        }
        
        return str.substr(s, e-s+1); // return palindrom string
    }
};
