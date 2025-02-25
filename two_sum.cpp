class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int first = 0; first < nums.size(); first++)
        {
            int second = first + 1;
            while (second < nums.size())
            {
                if (nums[first] + nums[second] == target)
                    return {first, second};
                second += 1;
            }
        }
        return {};
    }
};