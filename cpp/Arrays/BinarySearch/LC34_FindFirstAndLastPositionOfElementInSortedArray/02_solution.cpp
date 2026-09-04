class Solution {
    int searchLowerIndex(vector<int>& nums, int target) {
        int left = 0, right = static_cast<int>(nums.size()) - 1;
        int lower_index = -1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] < target) {
                left = mid + 1;
            }
            else if(nums[mid] > target) {
                right = mid - 1;
            }
            else {
                lower_index = mid;
                right = mid - 1;
            }
        }
        return lower_index;
    }
    int searchUpperIndex(vector<int>& nums, int target) {
        int left = 0, right = static_cast<int>(nums.size()) - 1;
        int upper_index = -1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] < target) {
                left = mid + 1;
            }
            else if(nums[mid] > target) {
                right = mid - 1;
            }
            else {
                upper_index = mid;
                left = mid + 1;
            }
        }
        return upper_index;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return { 
            searchLowerIndex(nums, target),
            searchUpperIndex(nums, target)
        };
    }
};