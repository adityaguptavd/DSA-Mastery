class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        size_t m = nums1.size();
        size_t n = nums2.size();
        size_t N = m + n;
        size_t left_size = (N + 1) / 2;
        if(m > n) {
            swap(nums1, nums2);
            swap(m, n);
        }
        size_t low = 0, high = m;
        while(low <= high) {
            size_t i = (low + high) / 2;
            size_t j = left_size - i;
            int nums1LeftLargest = i == 0 ? INT_MIN: nums1[i - 1];
            int nums1RightSmallest = i == m ? INT_MAX: nums1[i];
            int nums2LeftLargest = j == 0 ? INT_MIN: nums2[j - 1];
            int nums2RightSmallest = j == n ? INT_MAX: nums2[j];
            if(nums1LeftLargest > nums2RightSmallest) {
                high = i;
            }
            else if(nums2LeftLargest > nums1RightSmallest) {
                low = i + 1;
            }
            else {
                if(N % 2 == 0) {
                    return (static_cast<double>(max(nums1LeftLargest, nums2LeftLargest)) + min(nums1RightSmallest, nums2RightSmallest)) / 2.0;
                }
                else {
                    return max(nums1LeftLargest, nums2LeftLargest);
                }
            }
        }
        return 0.0;
    }
};
