class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> answers{};

        if (nums.size() < 4)
            return answers;

        sort(nums.begin(), nums.end());
        
        // select a number from array
        for (int select = 0; select < nums.size(); select++)
        {
            if (select > 0 && nums[select] == nums[select - 1])
                continue;

            // find all three sum equals to target substracting 
            int expectedTarget = target - nums[select];
            // three sum algorithm
            for (int first = select + 1; first < nums.size() - 2; first++)
            {
                // avoid duplicate quadruplets and triplets by skipping the same element
                if (first > select + 1 && nums[first] == nums[first - 1])
                    continue;

                int left = first + 1; 
                int right = nums.size() - 1;
                while (left < right)
                {
                    long sum = static_cast<long>(nums[first]) + static_cast<long>(nums[left]) + static_cast<long>(nums[right]);

                    if (sum == expectedTarget)
                    {
                        answers.push_back({ nums[select], nums[first], nums[left], nums[right] });

                        while(left < right && nums[left] == nums[left + 1])
                            left++;
                        
                        while(left < right && nums[right] == nums[right - 1])
                            right--;

                        left++;
                        right--;
                    }
                    else if (sum < expectedTarget)
                    {
                        left++;
                    }
                    else
                    {
                        right--;
                    }
                }
            }
        }
        return answers;
    }
};