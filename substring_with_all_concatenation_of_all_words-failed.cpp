class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int inputLength = s.length();
        int totalWords = words.size();
        int wordLength = words[0].length();
        int concateLength = totalWords * wordLength;
        std::sort(words.begin(), words.end());
        vector<int> answers{};
        for (int search = 0; search <= inputLength - concateLength; search++)
        {
            vector<string> leftWords = words;
            for (int subSearch = search; subSearch < concateLength + search; subSearch += wordLength)
            {
                bool found = false;
                string word(s.begin() + subSearch, s.begin() + subSearch + wordLength);
                for (int index = 0; index < leftWords.size(); index++)
                {
                    if (leftWords[index] < word)
                        continue;
                    else if (leftWords[index] == word)
                    {
                        found = true;
                        leftWords.erase(leftWords.begin() + index);
                        break;
                    }
                    else
                    {
                        found = false;
                        break;
                    }
                }

                if (found)
                    continue;
                else
                    break;
            }

            if (leftWords.size() == 0)
                answers.push_back(search);
            else
                continue;
        }
        return answers;
    }
};