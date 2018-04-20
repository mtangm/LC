/*
 *
Implement int sqrt(int x).

Compute and return the square root of x.

x is guaranteed to be a non-negative integer.

 */

class Solution {
public:
    int mySqrt(int x) {
        int start = 1, end = x/2;
        
        if (x==0||x==1) return x;
        
        int middle;
        int lastMiddle;

        while (start<=end)
        {
            middle=(start+end)/2; // make sure middle wont' be 0
            
            int remind= x / middle;
            
            if (remind == middle)
            {
                return middle;
            }
            
            if (remind<middle)
            {
                end = middle-1;
            }
            else
            {
                start = middle+1;
                lastMiddle=middle;
            }
        }
        
        return lastMiddle;
    }
};
