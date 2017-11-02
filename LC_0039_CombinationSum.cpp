/*
 Given a set of candidate numbers (C) (without duplicates) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [2, 3, 6, 7] and target 7, 
A solution set is: 
[
  [7],
  [2, 2, 3]
]
 */

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        
        vector<vector<int>> result;
        std::sort(candidates.begin(),candidates.end());
        vector<int> interresult;
        comb(candidates,0,result,target,interresult);
        
        return result;
    }
    
    void comb(vector<int> &candidates, int start, vector<vector<int>> &result, int target, vector<int> interresult)
    {
        if (target==0)
        {
            result.push_back(interresult);
            return;
        }
        
        for (int i=start;i<candidates.size();i++)
        {
            if (candidates[i]>target) return;
            
            interresult.push_back(candidates[i]);
            comb(candidates, i, result, target-candidates[i], interresult);
            interresult.pop_back();
        }
    }
};
