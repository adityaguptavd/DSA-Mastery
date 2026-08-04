#include<iostream>
#include<vector>

using namespace std;

class NumArray {
    vector<int> prefix_sum;
public:
    NumArray(vector<int>& nums) {
        prefix_sum.reserve(nums.size());
        for(int elem: nums) {
            if(prefix_sum.empty()) {
                prefix_sum.push_back(elem);
            }
            else {
                int last_prefix_sum = prefix_sum.back();
                prefix_sum.push_back(last_prefix_sum + elem);
            }
        }
    }
    
    int sumRange(int left, int right) {
        if(left == 0) {
            return prefix_sum[right];
        }
        return prefix_sum[right] - prefix_sum[left - 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */