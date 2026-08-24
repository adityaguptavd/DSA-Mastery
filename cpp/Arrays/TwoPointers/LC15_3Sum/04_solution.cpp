#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int nums_size = static_cast<int>(nums.size());
        vector<vector<int>> triplets;
        sort(nums.begin(), nums.end());
        for(int i = 0; i <= nums_size - 3 && nums[i] <= 0;) {
            int required_sum = -nums[i];
            // apply two sum to find required sum
            int L = i + 1, R = nums_size - 1;
            while(L < R) {
                if(nums[L] + nums[R] == required_sum) {
                    triplets.push_back({ nums[i], nums[L], nums[R] });
                    // skip duplicates for L and R
                    do {
                        ++L;
                    } while(L < R && nums[L] == nums[L - 1]);

                    do {
                        --R;
                    } while(L < R && nums[R] == nums[R + 1]);
                }
                else if(nums[L] + nums[R] < required_sum) ++L;
                else --R;
            }
            do {
                ++i;
            } while(i <= nums_size - 3 && nums[i] == nums[i - 1]);
        }
        return triplets;
    }
};