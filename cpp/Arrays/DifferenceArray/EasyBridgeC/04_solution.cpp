#include<iostream>
#include<vector>
#include<climits>

using namespace std;

class Solution {
    public:
        int getMaxAfterApplyingOperations(vector<int> nums, vector<vector<size_t>> operations) {
            int n = nums.size();
            vector<int> diff(n + 1, 0);
            for(const auto& operation: operations) {
                size_t startIndex = operation[0];
                size_t endIndex = operation[1];
                ++diff[startIndex];
                --diff[endIndex + 1];
            }
            int current = 0;
            int max_value = INT_MIN;
            for(size_t i = 0; i < n; ++i) {
                current += diff[i];
                max_value = max(max_value, current + nums[i]);
            }
            return max_value;
        }
};