class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    //    std::set<int> uniqueSet(nums.begin(), nums.end());
    //    nums.clear();
    //    nums.resize(uniqueSet.size());
    //    std::copy(uniqueSet.begin(), uniqueSet.end(), nums.begin());
        for(int i = nums.size() - 1; i > 0; i--)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                nums.erase(nums.begin() + i);
            }
        }
        return nums.size();
    }
};