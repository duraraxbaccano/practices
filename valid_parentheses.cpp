class Solution {
public:
    bool isValid(string s) {
        std::vector<char> stack{};
        for(auto c: s)
        {
            switch(c) {
                case '(':
                case '{':
                case '[':
                    stack.push_back(c);
                    break;
                case ')':
                    if(stack.size() == 0 || stack.back() != '(')
                        return false;
                    else
                        stack.pop_back();
                    break;
                case '}':
                    if(stack.size() == 0 || stack.back() != '{')
                        return false;
                    else
                        stack.pop_back();
                    break;
                case ']':
                    if(stack.size() == 0 || stack.back() != '[')
                        return false;
                    else
                        stack.pop_back();
                    break;
                default:
                    return false;
            }
        }
        return stack.size() == 0;
    }
};