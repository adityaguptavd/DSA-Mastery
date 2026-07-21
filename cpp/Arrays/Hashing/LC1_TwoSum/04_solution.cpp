#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // create hashmap
        unordered_map<int, int> seen;
        // traverse array
        for(int i = 0; i < nums.size(); i++) {
            // compute complement
            int complement = target - nums[i];
            // check if complement exists
            auto it = seen.find(complement);
            if(it != seen.end()) {
                // if exists, then return stored index and current index
                return { it->second, i };
            }
            else {
                // if no, then store value -> index
                seen[nums[i]] = i;
            }
        }
        // should never reach according to constraints
        return { -1, -1 };
    }
};