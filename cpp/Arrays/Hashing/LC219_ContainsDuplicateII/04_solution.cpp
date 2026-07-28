#include<iostream>
#include<vector>
#include<unordered_map>
#include<cstdlib>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(k == 0 || nums.size() == 1) return false;
        // create hashmap
        unordered_map<int, size_t> elem_to_idx_mp;
        for(size_t i = 0; i < nums.size(); ++i) {
            auto it = elem_to_idx_mp.find(nums[i]);
            if(it != elem_to_idx_mp.end()) {
                if((i - it->second) <= k) return true;
                else it->second = i;
            }
            else {
                elem_to_idx_mp.emplace(nums[i], i);
            }
        }
        return false;
    }
};