class Solution {
public:
    string intToRoman(int num) {
        std::vector<char> words;
        generateRoman(words, num / 1000, 'M', 'M', 'M');
        generateRoman(words,  (num % 1000) / 100, 'M', 'D', 'C');
        generateRoman(words, (num % 100) / 10, 'C', 'L', 'X');
        generateRoman(words, num % 10, 'X', 'V', 'I');
        return std::string(words.begin(), words.end());
    }

    void generateRoman(std::vector<char>& words, int digit, char ten, char five, char one)
    {
        switch (digit) {
            case 1:
                words.push_back(one);
                return;
            case 2:
                words.push_back(one);
                words.push_back(one);
                return;
            case 3:
                words.push_back(one);
                words.push_back(one);
                words.push_back(one);
                return;
            case 4:
                words.push_back(one);
                words.push_back(five);
                return;
            case 5:
                words.push_back(five);
                return;
            case 6:
                words.push_back(five);
                words.push_back(one);
                return;
            case 7:
                words.push_back(five);
                words.push_back(one);
                words.push_back(one);
                return;
            case 8:
                words.push_back(five);
                words.push_back(one);
                words.push_back(one);
                words.push_back(one);
                return;
            case 9:
                words.push_back(one);
                words.push_back(ten);
            case 0:
            default:
                return;
        }
    }
};