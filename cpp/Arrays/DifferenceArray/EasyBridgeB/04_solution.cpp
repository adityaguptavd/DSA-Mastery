#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool checkLimit(int n, vector<vector<int>>& updates, int limit) {
        vector<int> diff(n + 1, 0);
        for(const auto& update: updates) {
            int start_index = update[0];
            int end_index = update[1];
            int value = update[2];
            diff[start_index] += value;
            diff[end_index + 1] -= value;
        }
        int current = 0;
        for(int i = 0; i < n; ++i) {
            current += diff[i];
            if(current > limit) return false;
        }
        return true;
    }
};