class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() < 2)
            return;
        for (int next = nums.size() - 2; next >= 0; next--)
        {
            if (nums[next] < nums[next + 1])
            {
                int minMax = nums[next + 1];
                int loc = next + 1;
                for (int search = next + 2; search < nums.size(); search++)
                {
                    if (nums[search] < minMax && nums[search] > nums[next])
                    {
                        minMax = nums[search];
                        loc = search;
                    }
                }
                std::swap(nums[next], nums[loc]);
                std::sort(nums.begin() + next + 1, nums.end());
                return;
            }
        }
        std::sort(nums.begin(), nums.end());
        return;
    }
};