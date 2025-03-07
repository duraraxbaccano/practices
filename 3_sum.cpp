class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> result;
        int n = nums.size();

        // Sort the array to apply two-pointer technique
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; ++i)
        {
            // Avoid duplicate triplets by skipping the same element
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int left = i + 1, right = n - 1;
            while (left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0)
                {
                    result.push_back({nums[i], nums[left], nums[right]});

                    // Move left pointer and avoid duplicates
                    while (left < right && nums[left] == nums[left + 1])
                        ++left;
                    // Move right pointer and avoid duplicates
                    while (left < right && nums[right] == nums[right - 1])
                        --right;

                    // Move both pointers after storing the result
                    ++left;
                    --right;
                }
                else if (sum < 0)
                {
                    ++left; // Increase sum by moving left pointer
                }
                else
                {
                    --right; // Decrease sum by moving right pointer
                }
            }
        }

        return result;
    }
};