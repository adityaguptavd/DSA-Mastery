#include<iostream>
#include<vector>
#include<numeric>

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int left_sum = 0;
        int total_sum = accumulate(nums.begin(), nums.end(), 0);
        size_t nums_size = nums.size();
        for(size_t i = 0; i < nums_size; ++i) {
            if(left_sum == (total_sum - left_sum - nums[i])) {
                return static_cast<int>(i);
            }
            left_sum += nums[i];
        }
        return -1;
    }
};