class Solution {
public:
    bool isMatch(string s, string p) {
        //   a a a b _
        // a 1 1 1 1 0
        // * 0 0 0 0 0
        // . 0 0 0 1 0
        // _ 0 0 0 0 1
        std::vector<std::vector<bool>> matchMatrix(s.size() + 1, std::vector<bool>(p.size() + 1, false));
        // empty input matches empty pattern
        matchMatrix[s.length()][p.length()] = true; 
        // back tracking string with pattern
        for (int sIndex = s.length(); sIndex >= 0; sIndex--)
            for (int pIndex = p.length() - 1; pIndex >= 0; pIndex--) {
                bool posMatched = (sIndex < s.length() && (p[pIndex] == s[sIndex] || p[pIndex] == '.'));
                if (pIndex + 1 < p.length() && p[pIndex + 1] == '*')
                {
                  // if next is *, look for zero match or 1+ match from here   
                  matchMatrix[sIndex][pIndex] = matchMatrix[sIndex][pIndex + 2] || (posMatched && matchMatrix[sIndex + 1][pIndex]);
                } else {
                    // should all match from here   
                    matchMatrix[sIndex][pIndex] = posMatched && matchMatrix[sIndex + 1][pIndex + 1];  
                }
            }
        return matchMatrix[0][0];
    }
};