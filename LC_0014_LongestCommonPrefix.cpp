/* Write a function to find the longest common prefix string amongst an array of strings.
 *
 *
 */

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string pre;
        
        if (strs.size()==0)
        {
            return pre;
        }
        
        string first= strs[0];
        
        for (int i=0;i<first.length();i++)
        {
            int k;
            for (k=1;k<strs.size();k++)
            {
                if (strs[k].size()<i+1 || strs[k].at(i) != first.at(i))
                {
                    break;
                }
            }
            
            if (k == strs.size())
            {
                // found in all strings
                pre += first.at(i);
            }
            else
            {
                break;
            }
        }
        
        return pre;
    }
};
