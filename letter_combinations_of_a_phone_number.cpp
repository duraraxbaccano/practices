class Solution {
public:
    std::vector<char> two{'a', 'b', 'c'};
    std::vector<char> three{'d', 'e', 'f'};
    std::vector<char> four{'g', 'h', 'i'};
    std::vector<char> five{'j', 'k', 'l'};
    std::vector<char> six{'m', 'n', 'o'};
    std::vector<char> seven{'p', 'q', 'r', 's'};
    std::vector<char> eight{'t', 'u', 'v'};
    std::vector<char> nine{'w', 'x', 'y', 'z'};
    std::map<char, std::vector<char>> dict{
        { '2', two },
        { '3', three },
        { '4', four },
        { '5', five },
        { '6', six },
        { '7', seven },
        { '8', eight },
        { '9', nine },
    };
    vector<string> letterCombinations(string digits) {
        if (digits.length() == 0)
            return {};

        std::vector<string> combinations{""};
        for (int index = 0; index < digits.length(); index++)
        {
            std::vector<char>& letters = dict[digits[index]];
            std::vector<string> buffer{};
            for (auto s: combinations)
                for (auto c: letters)
                    buffer.push_back(s + c);
            combinations = std::move(buffer);
        }
        return combinations;
    }


};