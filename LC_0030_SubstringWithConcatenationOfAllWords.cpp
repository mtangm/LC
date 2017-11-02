/*
 *
 *
 * You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.

For example, given:
s: "barfoothefoobarman"
words: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter).
*/

class Solution {
public:
    
    // referred the shortest java solution.
    // created the following solution by myself.
    // not O(n)
    
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> M; // word -> #of_occurrances
        for (auto& w : words)
        {
            auto it = M.find(w);
            if (it == M.end())
            {
                M[w] = 1;   
            }
            else
            {
                it->second++;
            }
        }
        
        // init
        int wlen = words[0].size();
        int wcount = words.size();
        
        vector<int> result;
        if (wlen*wcount > s.size()) // edge case
        {
            return result;
        }
        
        // try each substring in s
        for (int i = 0; i <= s.size() - wlen * wcount; i++)
        {
            unordered_map<string, int> tmpM = M;
            int k = 0;
            while (k < wcount)
            {
                string sub = s.substr(i+k*wlen, wlen);
                auto it = tmpM.find(sub);
                if (it == tmpM.end())
                {
                    break;
                }
                
                if (--it->second == 0)
                {
                    tmpM.erase(it);
                }
                
                k++;
            }
            
            if (tmpM.empty())
            {
                result.emplace_back(i);
            }
        }
        
        return result;
    }
};
