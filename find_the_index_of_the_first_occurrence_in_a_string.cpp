class Solution {
public:
    int strStr(string haystack, string needle) {
        int matched = 0;
        for (int loc = 0; loc < haystack.length(); loc++)
        {
            if (haystack[loc] != needle[matched])
            {
                continue;
            }

            int candidate = loc;
            do {
                matched++;
                candidate++;
                if (matched == needle.length())
                    return loc;
            } while (haystack[candidate] == needle[matched]);
            matched = 0;
        }
        return -1;
    }
};