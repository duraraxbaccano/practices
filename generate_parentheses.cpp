class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> answers{"(())", "()()"};
        std::unordered_set<std::string> uniqueSet{};
        if (n == 1)
            return {"()"};
        else if (n == 2)
            return {"(())", "()()"};
        
        for(int layer = 2; layer < n; layer++)
        {
            int dequeueNum = answers.size();
            uniqueSet.clear();
            while (dequeueNum > 0)
            {   
                string brackets = answers.front();
                answers.erase(answers.begin());
                size_t startPos = 0;
                while ((startPos = brackets.find("()", startPos)) != std::string::npos) {
                    string type1 = brackets;
                    string type2 = brackets;
                    uniqueSet.insert(type1.replace(startPos, 2, "(())"));
                    uniqueSet.insert(type2.replace(startPos, 2, "()()"));
                    startPos += 2; // Step out {}
                }
                dequeueNum--;
            }
            answers.resize(uniqueSet.size());
            std::copy(uniqueSet.begin(), uniqueSet.end(), answers.begin());
        }
        return answers;
    }
};