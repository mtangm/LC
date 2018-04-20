/*
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)

*/

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {

        vector<string> ips = restore(s, 4);
        return ips;
    }
    
    
    vector<string> restore(string s, int numOfFields)
    {
        vector<string> ip;
        
        if (s.size() < numOfFields)
        {
            return ip;
        }
        
        if (numOfFields==1)
        {
            /* need to consider the case like:
            Input: "010010" 
            Output: 
                ["0.1.0.010","0.1.00.10","0.1.001.0","0.10.0.10","0.10.01.0","0.100.1.0","01.0.0.10","01.0.01.0","01.00.1.0","010.0.1.0"]               Expected: 
                ["0.10.0.10","0.100.1.0"]
            */

            if (atoi(s.c_str()) <= 255 && (s.size()==1 || s.size() >1 && s[0] != '0'))
            {
                ip.push_back(s);
            }
            return ip;
        }
        
        for (int i=0;i<3 && i < s.size()-1 && (i + numOfFields <= s.size());i++)
        {
            string head = s.substr(0,i+1); // i+1 is the length
            
            if (head.size() >1 && head[0]=='0' || atoi(head.c_str()) > 255)
            {
                continue;
            }
            
            vector<string> tails=restore(s.substr(i+1), numOfFields-1);
            if (tails.size()!=0)
            {
                for (int i = 0; i < tails.size(); i++)
                {
                    ip.push_back(head+"."+tails[i]);
                }
            }
        }
        
        return ip;
    }
};
