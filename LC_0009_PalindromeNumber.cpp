/*
 *
 * Determine whether an integer is a palindrome. Do this without extra space.

click to show spoilers.

Some hints:
Could negative integers be palindromes? (ie, -1)

If you are thinking of converting the integer to string, note the restriction of using extra space.

You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?

There is a more generic way of solving this problem.
 *
 *
 */
class Solution {
public:
    bool isPalindrome(int x) {
        int radix=1;
        
        if (x<0) return false;
        
        while (x/radix>=10)
        {
            radix*=10;
        }
        
        while (radix>1)
        {
            if (x/radix != x%10)
            {
                return false;
            }
            
            x %= radix;
            x /= 10;
            radix /= 100;
        }
        return true;
    }
};
