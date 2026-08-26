#include<iostream>
#include<vector>

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        // initialize the window of size k
        int left = 0, right = k - 1;
        // calculate the sum of the elements in initialized window
        long long current_sum = 0;
        for(int i = 0; i <= right; ++i) {
            current_sum += nums[i];
        }
        // initialize maximum sum
        long long max_sum = current_sum;
        // shift the window
        ++left; ++right;
        // size of the given array nums
        int nums_size = static_cast<int>(nums.size());
        while(right < nums_size) {
            // find sum of the current window by eliminating the leaving element and
            // including the entering element
            current_sum = current_sum - nums[left - 1] + nums[right];
            // update max sum
            max_sum = max(max_sum, current_sum);
            // shift the window
            ++left; ++right;
        }
        // return max average
        return static_cast<double>(max_sum) / k;
    }
};