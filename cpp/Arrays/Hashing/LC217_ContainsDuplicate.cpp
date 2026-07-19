#include<iostream>
#include<unordered_set>
#include<vector>

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.size() <= 1) return false;
        unordered_set<int> seen;
        for(int x: nums) {
            if(seen.find(x) != seen.end()) return true; // we can also use seen.contains(x) supported by C++ 20
            seen.insert(x);
        }
        return false;
    }
};