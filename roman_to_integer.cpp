class Solution {
public:
    int romanToInt(string s) {
        int sum = 0;
        int index = s.length() - 1;
        int previousDigit = 0;
        while (index >= 0)
        {
            switch (s[index]) {
                case 'I':
                    sum += (previousDigit > 1) ? -1 : 1;
                    previousDigit = 1;
                break;
                case 'V':
                    sum += 5;
                    previousDigit = 5;
                break;
                case 'X':
                    sum += (previousDigit > 10) ? -10 : 10;
                    previousDigit = 10;
                break;
                case 'L':
                    sum += 50;
                    previousDigit = 50;
                break;
                case 'C':
                     sum += (previousDigit > 100) ? -100 : 100;
                     previousDigit = 100;
                break;
                case 'D':
                    sum += 500;
                    previousDigit = 500;
                break;
                case 'M':
                    sum += 1000;
                    previousDigit = 1000;
                break;
                default:
                    return sum;
            }
            index--;
        }
        return sum;
    }
};