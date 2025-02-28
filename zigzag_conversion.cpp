class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;
        auto rows = std::vector<std::vector<char>>(numRows); 
        std::string output;
        output.reserve(s.length());
        int colAndOffset = numRows + numRows - 2;
        int index = 0;
        while(index < s.length())
        {
            int rowPos = index % colAndOffset;
            rowPos = (rowPos >= numRows) ? colAndOffset - rowPos : rowPos;
            rows[rowPos].push_back(s[index]);
            index++;
        }
        for (auto row : rows)
        {
            output.append(row.begin(), row.end());
        }
        return output;
    }
};