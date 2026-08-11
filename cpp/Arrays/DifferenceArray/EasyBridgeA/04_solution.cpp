#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void getModifiedArray(vector<int>& nums, vector<vector<int>>& updates) {
        vector<int> diff(nums.size() + 1, 0);
        for(const auto &update: updates) {
            int start_index = update[0];
            int end_index = update[1];
            int value = update[2];
            diff[start_index] += value;
            diff[end_index + 1] -= value;
        }
        int current = 0;
        for(size_t i = 0; i < nums.size(); ++i) {
            current += diff[i];
            nums[i] += current;
        }
    }
};