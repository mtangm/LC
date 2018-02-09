/*
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        vector<vector<int> > results;
        if (k == 0 || n==0)
        {
            return results;
        }
        
        if (k > n)
        {
            return results;
        }
        
        if (k == n)
        {
            vector<int> comb;
            for (int x = 1; x <= n; x++)
            {
                comb.push_back(x);
            }
            results.push_back(comb);
            return results;
        }
        
        // n > k
        
        // combination with n
        vector<vector<int> > tmp;

        if (k == 1)
        {
            vector<int> one;
            one.push_back(n);
            tmp.push_back(one);
        }
        else // k > 1
        {
            tmp = combine(n-1, k-1);
            for (int i = 0; i < tmp.size(); i++)
            {
                tmp[i].push_back(n);
            }
        }
        

        // combination without n
        results = combine(n - 1, k);
        
        // merge two combinations
        results.insert(results.end(), tmp.begin(), tmp.end());
        
        return results;
        
    }
};
