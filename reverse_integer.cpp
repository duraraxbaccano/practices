class Solution {
public:
    int reverse(int x) {
        int output = 0;
        while (x != 0)
        {
            if (output > INT_MAX / 10 || output < INT_MIN / 10)
                return 0;
            output *= 10;
            output += (x % 10);
            x /= 10;
        }
        return output;
    }
};