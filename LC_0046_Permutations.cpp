/*
 * Given a collection of distinct numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]

*/

class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > result;
        if (num.size()==0)
        {
            return result;
        }
        
        perm(result, num, 0, num.size()-1);
        
        return result;
    }
    
    void perm(vector<vector<int> >& res, vector<int>& num, int start, int end)
    {
        if (start == end)
        {
            res.push_back(num);
            return;
        }
        
        for(int j = start; j<=end;j++)
        {
            // swap item at start and j
            int tmp=num[start];
            num[start]=num[j];
            num[j]=tmp;
            
            perm(res, num, start+1, end);
            
            tmp=num[start];
            num[start]=num[j];
            num[j]=tmp;
        }
        
    }
    
};
