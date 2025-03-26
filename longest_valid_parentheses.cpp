class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.length() == 0)
            return 0;
        int longestLength = 0;
        std::vector<bool> count(s.length(), false);
        std::vector<int> leftParentheses{};
        int left = 0;
        int last = s.length() - 1;
        while (left < last && s[left] != '(')
            left++;
        while (left < last && s[last] != ')')
            last--;
        for (int index = left; index <= last; index++)
        {
            if (s[index] == '(')
                leftParentheses.push_back(index);
            else if (leftParentheses.size() != 0)
            {
                count[leftParentheses.back()] = true;
                count[index] = true;
                leftParentheses.pop_back();
            }
            else
            {
                leftParentheses.clear();
            }
        }

        int validParentheses = 0;
        for (int index = left; index <= last; index++)
        {
            if (!count[index])
            {
                validParentheses = 0;
                continue;
            }
            else
            {
                validParentheses++;
                if (validParentheses > longestLength)
                {
                    longestLength = validParentheses;
                }
            }
        }
        return longestLength;
    }
};