#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int prefix_sum = 0;
        size_t num_of_sub_arrays = 0;
        unordered_map<int, size_t> prefix_sum_frequency;
        for(int elem: nums) {
            prefix_sum += elem;
            // if current prefix sum itself becomes equal to target value k
            if(prefix_sum == k) {
                ++num_of_sub_arrays;
            }
            int required_prefix_sum = prefix_sum - k;
            auto it = prefix_sum_frequency.find(required_prefix_sum);
            if(it != prefix_sum_frequency.end()) {
                num_of_sub_arrays += it->second;
            }
            prefix_sum_frequency[prefix_sum] += 1;
        }
        return num_of_sub_arrays;
    }
};