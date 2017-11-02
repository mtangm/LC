/*
 *
Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT.
*/

class Solution {
public:
	int divide(int dividend, int divisor) {
		long long res = 1;
		int sign = 1;

		if (dividend < 0 && divisor>0 || dividend > 0 && divisor < 0)
		{
			sign = -1;
		}

		res = sign * this->divideHelp(abs((long long)dividend), abs((long long)divisor));
		if (res > INT_MAX || res < INT_MIN)
		{
			res = INT_MAX;
		}

		return res;
	}

	long long divideHelp(long long dividend, long long divisor)
	{
		if (dividend == 0) return 0;
		if (divisor == 0) return 0x7FFFFFF;

		if (dividend < divisor)
		{
			return 0;
		}

		long long times = 1;
		long long div = divisor;
		while (dividend >= div << 1)
		{
			times <<= 1;
			div <<= 1;
		}

		long long subRes = divideHelp(dividend - div, divisor);

		long long res = times + subRes;
		return res;
	}
};
