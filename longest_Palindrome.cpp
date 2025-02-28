class Solution {
public:
    string longestPalindrome(string s) {
        int first = 0;
        int end = s.length() - 1;
        int max = 0;
        std::string maxPalindrome;

        if (s.size() < 2)
            return s;

        while (s.length() - max > first)
        {
            while(s[first] != s[end])
                end--;

            if (isPalindromic(s, first, end))
            {
                if (end - first + 1 > max)
                {
                    max = end - first + 1;
                    maxPalindrome = s.substr(first, end - first + 1);;

                }
            }
            else
            {
                end--;
                continue;
            }
            first++;
            end = s.length() - 1;
        }

        return maxPalindrome;
    }

    bool isPalindromic(string s, int first, int end)
    {
        while (first < end)
        {
            if (s[first] != s[end])
                return false;
            first++;
            end--;
        }
        return true;
    }
};