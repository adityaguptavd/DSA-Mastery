// Kadane's Algorithm
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int best_ending = nums[0];
        int best_so_far = nums[0];
        size_t n = nums.size();
        for(size_t i = 1; i < n; ++i) {
            best_ending = max(best_ending + nums[i], nums[i]);
            best_so_far = max(best_ending, best_so_far);
        }
        return best_so_far;
    }
};