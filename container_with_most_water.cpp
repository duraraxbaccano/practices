class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        int first = 0;
        int last = height.size() - 1;
        while (first < last)
        {
            maxArea = std::max(maxArea, std::min(height[first], height[last]) * std::abs(last - first));
            if (height[first] < height[last])
            {
                int target = height[first];
                while (first < last && height[first] <= target)
                    first++;
            }
            else
            {
                 int target = height[last];
                while (first < last && height[last] <= target)
                    last--;
            }
        }
        return maxArea;
    }
};