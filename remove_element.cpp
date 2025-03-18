class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // for (int i = nums.size() - 1; i >= 0; i--)
        // {
        //     if (nums[i] == val)
        //     {
        //         nums.erase(nums.begin() + i);
        //     }
        // }
        int left = 0;
        int last =  nums.size() - 1;
        while (last >= 0 && nums[last] == val)
            last--;
        while (left < last)
        {
            if (nums[left] == val)
            {
                std::swap(nums[left], nums[last]);
                while (last >= 0 && nums[last] == val)
                    last--;
            }
            left++;
        }
        return last + 1;
        // return nums.size();
    }
};