class Solution {
public:
    bool isPalindrome(int x) {
        std::vector<int> digits{};
        if (x < 0)
            return false;
        else if (x == 0)
            return true;
        else
        {}

        while (x > 0)
        {
            digits.push_back(x % 10);
            x /= 10;
        }

        int start = 0;
        int end = digits.size() - 1;
        while (start < end)
        {
            if (digits[start] != digits[end])
                return false;
            start++;
            end--;
        }
        return true;
    }
};