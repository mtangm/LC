/*
 * not fast
 */

class Solution {
public:
    int atoi(const char *str) {
        int r = 0;
        int sign = 1;
 
        // skip leading spaces
        while(isspace(*str))
        {
            str++;
        }
        
        // check leading - or +
        if (*str=='-')
        {
            sign=-1;
        }
        if (*str=='-' || *str=='+')
        {
            str++;
        }
        
        while(isdigit(*str))
        {
            
            if (r > INT_MAX / 10 || (r == INT_MAX/10 && *str - '0' > INT_MAX % 10))
            {
                return sign == 1 ? INT_MAX : INT_MIN;
            }
            
            r = r*10+ (*str - '0');
            
            str++;
        }
        
        r *= sign;

        return r;
    }
};
