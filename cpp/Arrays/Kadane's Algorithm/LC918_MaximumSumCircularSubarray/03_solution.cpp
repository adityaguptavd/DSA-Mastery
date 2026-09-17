class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int min_ending = nums[0], max_ending = nums[0], best_so_far = nums[0], total_sum = nums[0], min_so_far = nums[0];
        bool isAllNegative = true;
        for(size_t i = 1; i < nums.size(); ++i) {
            if(nums[i] > 0) isAllNegative = false;
            max_ending = max(max_ending + nums[i], nums[i]);
            min_ending = min(min_ending + nums[i], nums[i]);
            best_so_far = max(best_so_far, max_ending);
            min_so_far = min(min_so_far, min_ending);
            total_sum += nums[i];
        }
        if(isAllNegative) return best_so_far;
        return max(best_so_far, total_sum - min_so_far);
    }
};