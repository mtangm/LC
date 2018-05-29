/*
 * Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

Example 1:

Input: [5,7]
Output: 4
Example 2:

Input: [0,1]
Output: 0

*/

class Solution {
public:
    
    //
    // refered the other's solution.
    // The main idea is to find the common leading bits.
    //
    int rangeBitwiseAnd(int m, int n) {
        
        while (m < n)
        {
            n &= n - 1; // remove the right most bit
        }
        
        return n;
    }
};
