/*
 * Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
*/


class Solution {
public:
    string addBinary(string a, string b) {
        string res;

        int sizea = a.size();
        int sizeb = b.size();

        int carry = 0;

        for (int i=0;i<min(sizea,sizeb);i++)
        {
            char ca = a[sizea-1-i];
            char cb = b[sizeb-1-i];

            int ia = ca - '0';
            int ib = cb - '0';

            int ir = ia + ib + carry;
            carry = ir >= 2 ? 1 : 0;
            ir %= 2;

            // insert at position 0
            res.insert(0, ir == 0 ? "0" : "1");
        }

        if (sizea!=sizeb)
        {
            string& largerStr = (sizea > sizeb) ? a : b;;

            for (int i = largerStr.size() - min(sizea, sizeb) - 1; i >=0; i--)
            {
                int v = largerStr[i] - '0';
                int ir = v + carry;
                carry = (ir >=2) ? 1 : 0;
                ir %= 2;

                // insert value to result
                res.insert(0, ir == 0 ? "0" : "1");
            }
        }

        if (carry == 1)
        {
            res.insert(0, "1");
        }

        return res;
     }
};
