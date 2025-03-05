class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string& commonPrefix = strs[0];
        int lastIndex = strs[0].length() - 1;
        for(int i = 1; i < strs.size(); i++)
        {
            lastIndex = (lastIndex < strs[i].length()) ? lastIndex : strs[i].length() - 1;
            for(int s = lastIndex; s >= 0; s--)
            {
                if (commonPrefix[s] == strs[i][s])
                {
                    continue;
                }
                else
                {
                    lastIndex = s - 1;
                }
            }
            if (lastIndex < 0)
                return "";
        }
        return commonPrefix.substr(0, lastIndex + 1);
    }
};