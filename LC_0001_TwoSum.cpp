class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        map<int, int> M;//value_index_map;
        int index1=0;
        int index2 = 0;
        vector<int> res;
        
        for (int i = 0; i < numbers.size(); i++)
        {
            if (M.find(target - numbers[i]) != M.end())
            {
                index1=M[target-numbers[i]];
                index2=i;
                res.push_back(index1);
                res.push_back(index2);
                break;
            }

            M[numbers[i]] = i;
        }
        
        return res;       
        
    }
};
