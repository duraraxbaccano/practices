class Solution {
public:
    int myAtoi(string s) {
        int output = 0;
        long limitCheck = 0;
        int index = 0;
        bool isNegative = false;
        bool detectedDigit = false;
        while(index < s.length())
        {
            switch(s[index])
            {
                case '0':
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                    detectedDigit = true;
                    limitCheck = static_cast<long>(output) * 10;
                    limitCheck += static_cast<int>(s[index]) - 48;
                    if (limitCheck > INT_MAX)
                        return (isNegative) ? INT_MIN : INT_MAX;
                    else if (limitCheck == INT_MAX)
                        return (isNegative) ? INT_MIN + 1 : INT_MAX;
                    else
                    {
                        output *= 10;
                        output += static_cast<int>(s[index]) - 48;
                    }
                    break;
                case '-':
                    if (detectedDigit)
                        goto teardown;
                    else
                        isNegative = true;
                        detectedDigit = true;
                    break;
                case '+':
                    if (detectedDigit)
                        goto teardown;
                    detectedDigit = true;
                    break;
                case ' ':
                    if (detectedDigit)
                        goto teardown;
                    break;
                default:
                    goto teardown;
            }
            index++;
        }
teardown: 
        return (isNegative) ? output * (-1) : output;
    }
};