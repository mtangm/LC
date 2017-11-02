/*
The count-and-say sequence is the sequence of integers with the first five terms as following:

1.     1
2.     11
3.     21
4.     1211
5.     111221
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth term of the count-and-say sequence.

Note: Each term of the sequence of integers will be represented as a string.

Example 1:

Input: 1
Output: "1"
Example 2:

Input: 4
Output: "1211"

*/

class Solution {
public:
    string countAndSay(int n) {
        string last;
        
        if (n==0)
        {
            return last;
        }
        
        if (n==1)
        {
            return string("1");
        }
        
        last = "1";
        
        for (int i =2;i<=n;i++)
        {
            string next;
            
            int count=1; // count of the same digits
            char digit=last[0]; // digit 
            
            for (int k=1;k<last.size();k++)
            {
                if (last[k]==digit)
                {
                    ++count;
                }
                else
                {
                    // current digit is different from the last one
                    next += std::to_string(count)+digit;
                    count = 1;
                }
                
                digit=last[k];
            }
            next += std::to_string(count)+digit;
            
            last = next;
        }
        
        return last;
    }
};
