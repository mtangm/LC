/*
 * Given an array of strings, group anagrams together.

For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
Return:

[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note: All inputs will be in lower-case.

*/

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        map<string, vector<string>> M;
        typedef map<string, vector<string>>::iterator IT;
        vector<string> res;
        
        for (int i=0; i < strs.size(); i++)
        {
            string key=getKey(strs[i]);
            M[key].push_back(strs[i]);
        }
        
        for (IT it = M.begin(); it !=M.end(); it++)
        {
            if (it->second.size() > 1)
            {
                for (int i = 0; i < it->second.size(); i++)
                {
                    res.push_back(it->second[i]);
                }
            }
        }
        
        return res;
    }
    
    string getKey(string str)
    {
        string key;
        int alpha[26]={0};
        
        for (int i=0; i<str.size();i++)
        {
            alpha[str[i]-'a']++;
        }
        
        for (int i = 0; i < 26; i++)
        {
            for (int j=0; j < alpha[i]; j++)
            {
                key += 'a'+i;
            }
        }
        
        return key;
    }
};
