class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.size() <= 1)
            return (nums.size() == 1 && nums[0] < target) ? 1 : 0;
        
        int left = 0;
        int right = nums.size() - 1;
        while (left < right)
        {
            int middle = (left + right) / 2;

            if (nums[middle] == target)
                return middle;
            else if (nums[left] == target || nums[left] > target)
                return left;
            else if (nums[right] == target)
                return right;
            else if (nums[right] < target)
                return right + 1;
            else if (nums[middle] > target)
            {
                if (middle - 1 <= left)
                    return left + 1;
                else if (nums[middle - 1] == target)
                    return middle - 1;
                else if (nums[middle - 1] < target)
                    return middle;
                else
                    right = middle;
            }
            else
            {
                if (middle + 1 >= right)
                    return right;
                else if (nums[middle + 1] >= target)
                    return middle + 1;
                else
                    left = middle;
            }
        }
        return left;
    }
};