class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max = 0;
        int first = 0;
        int end = 0;
        
        while (end < s.length())
        {
            char current = s[end];
            int currentIndex = end;
            while (currentIndex > first)
            {
                currentIndex--;
                if (s[currentIndex] == current)
                {
                    first = currentIndex + 1;
                }
            }
            end += 1;
            max = (end - first > max) ? end - first : max;
        }
        return max;
    }
};