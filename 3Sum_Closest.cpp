class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        int minDelta = std::abs(nums[0] + nums[1] + nums[2] - target);
        int sum = nums[0] + nums[1] + nums[2];
        int index = 0;

        if (sum == target)
            return target;

        while(index < nums.size())
        {
            int left = index + 1;
            int right = nums.size() - 1;

            while (left < right)
            {
                int newSum = nums[index] + nums[left] + nums[right];
                int newDiff = newSum - target;
                int newDelta = std::abs(newDiff);

                if (newDelta == 0)
                    return target;
                
                if (newDelta < minDelta)
                {
                    minDelta = newDelta;
                    sum = newSum;
                }

                if (newDiff > 0)
                    right--;
                else
                    left++;
            }
            index++;
        }
        return sum;
    }
};