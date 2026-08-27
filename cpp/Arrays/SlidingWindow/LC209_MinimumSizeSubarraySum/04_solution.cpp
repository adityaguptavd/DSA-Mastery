#include<iostream>
#include<vector>
#include<limits>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // initialize window of size 1
        int left = 0, right = 0;
        long long current_sum = static_cast<long long>(nums[right]);
        int min_size = nums[right] >= target ? 1: numeric_limits<int>::max();
        ++right;
        while(right < nums.size()) {
            current_sum += nums[right];
            while(current_sum >= target) {
                min_size = min(min_size, right - left + 1);
                current_sum -= nums[left];
                ++left;
            }
            ++right;
        }
        return min_size == numeric_limits<int>::max() ? 0: min_size;
    }
};