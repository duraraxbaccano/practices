class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = -1;
        int last = -1;
        if (nums.size() == 0)
            return {first, last};

        int left = 0;
        int right = nums.size() - 1;
        while (left <= right)
        {
            int middle = (left + right) / 2;
            
            if (nums[left] == target)
            {
                first = left;
            }

            if (nums[right] == target)
            {
                last = right;
            }

            if (first != -1 && last != -1)
                break;

            if (nums[middle] > target)
            {
                right = middle - 1;
            }
            else if (nums[middle] < target)
            {
                left = middle + 1;
            }
            else
            {
                if (first == -1)
                {
                    first = middle;
                    while (middle > left && nums[first - 1] == target)
                        first--;
                } 

                if (last == -1)
                {
                    last = middle;
                    while (last + 1 < right && nums[last + 1] == target)
                        last++; 
                }

                return { first, last };
            }
        } 
        return {first, last};
    }
};