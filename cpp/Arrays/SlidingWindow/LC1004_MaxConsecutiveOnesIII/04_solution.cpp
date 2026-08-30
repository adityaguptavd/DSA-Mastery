class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        // initialize left and right boundary of the window
        size_t left = 0, right = 0;
        // intialize counter for zeroes encountered in the window
        size_t zero_count = 0;
        // array size
        size_t n = nums.size();
        while(right < n) {
            if(nums[right] == 0) {
                ++zero_count;                
            }
            // if window is invalid shrink it
            if(zero_count > k) {
                ++left;
                // if the leaving element is zero
                if(nums[left - 1] == 0) {
                    --zero_count;
                }
            }
            // expand the window
            ++right;
        }
        // return the size of maximum valid window
        return static_cast<int>(right - left);
    }
};