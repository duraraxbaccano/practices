class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total = nums1.size() + nums2.size();
        int medianIndex = total / 2 + 1;
        double median = 0, previous = 0;
        int left = 0;
        int right = 0;
        while (left + right < medianIndex) 
        {
            previous = median;

            if (left >= nums1.size())
            {
                median = static_cast<double>(nums2[right]);
                right++;
                continue;
            }

            if (right >= nums2.size())
            {
                median = static_cast<double>(nums1[left]);
                left++;
                continue;
            }

            if (nums1[left] > nums2[right])
            {
                median = static_cast<double>(nums2[right]);
                right++;
            }
            else
            {
                median = static_cast<double>(nums1[left]);
                left++;
            }
        }
        return (total % 2 == 0) ? (median + previous) / 2 : median;
    }
};