/*
Implement pow(x, n).
*/

class Solution {
public:
    double myPow(double x, int n) {
        double r = powHelp(x, abs(n));
        return n > 0 ? r : 1 / r;
    }
    
    double powHelp(double x, int n)
    {
        if (n==0) return 1;
        
        double v = powHelp(x, n /2);
        
        if (n%2 == 0)
        {
            return v * v;
        }
        else
        {
            return v * v * x;
        }
    }
};
