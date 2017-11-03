/*
 *
 * Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example, 
Given s = "Hello World",
return 5.
*/

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        bool findFW=false; // find first word
        int len_prev=0, len_curr=0;
        
        for (int i=0; s[i]!='\0';i++)
        {
            if (s[i]==' ')
            {
                // preserve the previous word length
                if (findFW && len_curr!=0)
                {
                    len_prev=len_curr;
                    len_curr=0;
                }
            }
            else
            {
                // current word length
                len_curr++;
                findFW=true;
            }
        }
        
        return len_curr != 0 ? len_curr : len_prev;
    }
};
