/*
 * not quick enough
 * 3 years ago.
 * 14.70%
 */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int i=0; // start position of the substring
        int maxlen=0;
        
        for (int j=0;j<s.length();j++)
        {
            for (int k=i;k<j;k++)
            {
                // check if the current char exists in substring
                if(s[k]==s[j])
                {
                    maxlen=max(maxlen, j-i);
                    i=k+1; // move start of substring
                    break;
                }
            }
        }
        
        maxlen=max(maxlen, (int)s.length()-i);
        return maxlen;
    }
};
