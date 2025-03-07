class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> answers{};
        map<int, map<int, map<int, bool>>> inAnswers{};
        map<int, bool> foundTwoSum{};
        map<int, vector<std::pair<std::pair<int, int>, std::pair<int, int>>>> twoSumPairs{};

        for (int first = 0; first < nums.size(); first++)
        {
            for (int second = first + 1; second < nums.size(); second++)
            {
                int twoSum = nums[first] + nums[second];
                // save two sum locations and values
                if (!foundTwoSum[twoSum])
                {
                    twoSumPairs[twoSum] = {{{first, second}, {nums[first], nums[second]}}};
                    // label specific two sum existed
                    foundTwoSum[twoSum] = true;
                }
                else
                    twoSumPairs[twoSum].push_back({{first, second}, {nums[first], nums[second]}});
            }
        }

        for (int third = 0; third < nums.size(); third++)
        {
            // not found specific two sum, so continue
            if (!foundTwoSum[0 - nums[third]])
                continue;
            else
            {
                int expectedTwoSum = 0 - nums[third];
                for (auto p : twoSumPairs[expectedTwoSum])
                {
                    int first = p.first.first;
                    int second = p.first.second;
                    int firstNum = p.second.first;
                    int secondNum = p.second.second;
                    int thirdNum = nums[third];
                    if (first == third || second == third || inAnswers[firstNum][secondNum][thirdNum])
                        continue;
                    answers.push_back({firstNum, secondNum, thirdNum});
                    // remove duplicates number triplets
                    inAnswers[firstNum][secondNum][thirdNum] = true;
                    inAnswers[firstNum][thirdNum][secondNum] = true;
                    inAnswers[thirdNum][firstNum][secondNum] = true;
                    inAnswers[thirdNum][secondNum][firstNum] = true;
                    inAnswers[secondNum][thirdNum][firstNum] = true;
                    inAnswers[secondNum][firstNum][thirdNum] = true;
                }
            }
        }

        return answers;
    }
};