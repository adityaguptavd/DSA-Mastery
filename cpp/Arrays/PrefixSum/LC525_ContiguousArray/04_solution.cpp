#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> first_prefix_occurrence({{ 0, -1 }});
        int largest_subarray_length = 0;
        int running_prefix_sum = 0;
        int nums_size = static_cast<int>(nums.size());
        for(int i = 0; i < nums_size; ++i) {
            running_prefix_sum += nums[i] == 0 ? -1: 1;
            auto running_sum_first_occurrence_it = first_prefix_occurrence.find(running_prefix_sum);
            if(running_sum_first_occurrence_it != first_prefix_occurrence.end()) {
                largest_subarray_length = max(largest_subarray_length, i - running_sum_first_occurrence_it->second);
            }
            else {
                first_prefix_occurrence.emplace(running_prefix_sum, i);
            }
        }
        return largest_subarray_length;
    }
};