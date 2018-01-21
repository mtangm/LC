/*
Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.

You may assume the integer do not contain any leading zero, except the number 0 itself.

The digits are stored such that the most significant digit is at the head of the list.

*/

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        int carry = 0;
        
        for (int i = digits.size() - 1; i >= 0; i--)
        {
            int v;
            
            if (i == digits.size() - 1)
            {
                v = digits[i] + 1;
            }
            else
            {
                v = digits[i] + carry;
            }
            
            if (v > 9)
            {
                digits[i] = v % 10;
                carry = 1;
            }
            else
            {
                digits[i] = v;
                carry = 0;
            }
        }
        
        if (carry == 1)
        {
            digits.insert(digits.begin(), 1);
        }
        
        return digits;
    }
};
