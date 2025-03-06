class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> answers{};
        map<int, map<int, map<int, bool>>> inAnswers{};
        map<int, bool> foundTwoSum{};
        map<int, int> foundNumber{};
        for (int first = 0; first < nums.size(); first++)
        {
            int expectedTwoSum = 0 - nums[first];
            if (first != 0 && !foundTwoSum[expectedTwoSum])
                continue;

            for (int second = first + 1; second < nums.size(); second++)
            {
                int expectedNumber = expectedTwoSum - nums[second];
                if (first != 0 && foundNumber[expectedNumber] <= second)
                    continue;
                if (first != 0 && !inAnswers[nums[first]][nums[second]][expectedNumber])
                {
                    answers.push_back({nums[first], nums[second], expectedNumber}); 
                    inAnswers[nums[first]][nums[second]][expectedNumber] = true;
                    inAnswers[nums[first]][expectedNumber][nums[second]] = true;
                    inAnswers[expectedNumber][nums[first]][nums[second]] = true;
                    inAnswers[expectedNumber][nums[second]][nums[first]] = true;
                    inAnswers[nums[second]][expectedNumber][nums[first]] = true;
                    inAnswers[nums[second]][nums[first]][expectedNumber] = true;
                    continue;
                }

                for (int third = second + 1; third < nums.size(); third++)
                {
                    if (nums[first] + nums[second] + nums[third] == 0)
                    {                        
                        if (!inAnswers[nums[first]][nums[second]][nums[third]])
                        {
                            answers.push_back({nums[first], nums[second], nums[third]}); 
                            inAnswers[nums[first]][nums[second]][nums[third]] = true;
                            inAnswers[nums[first]][nums[third]][nums[second]] = true;
                            inAnswers[nums[third]][nums[first]][nums[second]] = true;
                            inAnswers[nums[third]][nums[second]][nums[first]] = true;
                            inAnswers[nums[second]][nums[third]][nums[first]] = true;
                            inAnswers[nums[second]][nums[first]][nums[third]] = true;
                        }
                    }
                    foundTwoSum[nums[second] + nums[third]] = true;
                    foundNumber[nums[third]] = third;
                }
            }
        }
        return answers;
    }
};