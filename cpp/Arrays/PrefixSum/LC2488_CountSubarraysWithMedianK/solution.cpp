class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        int n = static_cast<int>(nums.size());
        int pivot_index = find(nums.begin(), nums.end(), k) - nums.begin();
        unordered_map<int, int> left_balance_freq;
        int curr_balance_value = 0;
        for(int i = pivot_index - 1; i >= 0; --i) {
            if(nums[i] < k) {
                --curr_balance_value;
            }
            else if(nums[i] > k) {
                ++curr_balance_value;
            }
            ++left_balance_freq[curr_balance_value];
        }
        curr_balance_value = 0;
        int num_subarrays = left_balance_freq[0] + left_balance_freq[1] + 1;
        for(int i = pivot_index + 1; i < n; ++i) {
            if(nums[i] < k) {
                --curr_balance_value;
            }
            else if(nums[i] > k) {
                ++curr_balance_value;
            }
            num_subarrays += (
                left_balance_freq[-curr_balance_value] +
                left_balance_freq[1-curr_balance_value]
            );
            if(curr_balance_value == 0 || curr_balance_value == 1) {
                ++num_subarrays;
            }
        }
        return num_subarrays;
    }
};
