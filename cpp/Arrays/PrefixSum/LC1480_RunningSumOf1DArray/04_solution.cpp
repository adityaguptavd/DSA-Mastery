#include<vector>
using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        // create output array
        size_t nums_size = nums.size();
        vector<int> output(nums_size);
        output[0] = nums[0];
        for(size_t i = 1; i < nums_size; i++) {
            output[i] = output[i - 1] + nums[i];
        }
        return output;
    }
};