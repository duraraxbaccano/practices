class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> result;

    // not neccessary in the scenario
    //if (words.empty() || s.empty()) return result;

    int word_len = words[0].length();
    int word_count = words.size();
    int total_len = word_len * word_count;

    if (s.length() < total_len) return result;

    unordered_map<string, int> word_map;
    for (const string& word : words) {
        word_map[word]++;
    }

    for (int i = 0; i < word_len; ++i) {
        int left = i;
        int right = i;
        unordered_map<string, int> seen;

        while (right + word_len <= s.length()) {
            string word = s.substr(right, word_len);
            right += word_len;

            if (word_map.find(word) != word_map.end()) {
                seen[word]++;

                // If we’ve seen too many of this word, slide the window
                while (seen[word] > word_map[word]) {
                    string left_word = s.substr(left, word_len);
                    seen[left_word]--;
                    left += word_len;
                }

                // Valid window
                if (right - left == total_len) {
                    result.push_back(left);
                }
            } else {
                // Word not in word_map, reset window
                seen.clear();
                left = right;
            }
        }
    }

    return result;
    }
};