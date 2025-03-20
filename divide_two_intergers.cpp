class Solution {
public:
    int divide(int dividend, int divisor) {
        
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        
        bool isNegative = (dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0);
        long long positiveDividend = (dividend < 0) ? static_cast<long long>(dividend) * -1 : dividend;
        long long positiveDivisor = (divisor < 0) ? static_cast<long long>(divisor) * -1 :divisor;
        long long quotient = 0;

        while (positiveDividend >= positiveDivisor)
        {
            long long maxDivisor = positiveDivisor;
            long long factor = 1;

            while ( (maxDivisor << 1) <= positiveDividend)
            {
                maxDivisor <<= 1;
                factor <<= 1;
            }

            positiveDividend -= maxDivisor;
            quotient += factor;
        }
        return (isNegative) ? -quotient: quotient;
    }
};