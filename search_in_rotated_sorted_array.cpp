class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        /*
            1, 2, 3, 4, 5, 6

            4, 5, 6, 1, 2, 3
            6, 1, 2, 3, 4, 5
            2, 3, 4, 5, 6, 1
        */

        while (left <= right)
        {
            int middle = (left + right) / 2;

            if (nums[middle] == target)
                return middle;
            else if (nums[left] == target)
                return left;
            else if (nums[right] == target)
                return right;
            else if (nums[right] > nums[left])
            {
                if (nums[middle] < target)
                    left = middle + 1;
                else
                    right = middle - 1;
            }
            else
            {
                if (nums[middle] > nums[left]) // ascending is left
                {
                    if (nums[middle] > target && nums[left] < target)
                        right = middle - 1;
                    else
                        left = middle + 1;
                }
                else // ascending is right
                {
                    if (nums[middle] < target && nums[right] > target)
                        left = middle + 1;
                    else
                        right = middle - 1;
                }
            }
        }
        return -1;
    }
};