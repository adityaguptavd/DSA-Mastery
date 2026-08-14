#include<iostream>
#include<vector>

using namespace std;

class Solution {
    public:
        int getMaxOverlap(vector<vector<int>> intervals) {
            int maxOverlap = 0;
            vector<int> diff(100000 + 2, 0);
            for(const auto& interval: intervals) {
                int start = interval[0];
                int end = interval[1];
                ++diff[start];
                --diff[end + 1];
            }
            int prefixSum = 0;
            for(int i = 0; i <= 100000; ++i) {
                prefixSum += diff[i];
                maxOverlap = max(maxOverlap, prefixSum);
            }
            return maxOverlap;
        }
};