/*
 *
 * Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
 *
 */

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        if (haystack.empty()) return -1;
        
        int n = haystack.size();
        int m = needle.size();
        
        for (int i = 0; i<n; i++)
        {
            if (n - i < m) return -1;
            
            int j;
            for (j = 0; j < m; j++)
            {
                if (haystack[i+j]!=needle[j])
                {
                    break;
                }
            }
            
            if (j == m)
            {
                return i;
            }
        }
        
        return -1;
    }
};
