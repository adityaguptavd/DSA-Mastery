#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        vector<int> diff(52, 0);
        for(const auto& range: ranges) {
            int start = range[0];
            int end = range[1];
            ++diff[start];
            --diff[end + 1];
        }
        int current = 0; // current == 0 -> inactive range, current > 0 -> active range
        for(int i = 0; i <= 50; ++i) {
            current += diff[i];
            if(
                current == 0 &&
                i <= right &&
                i >= left
            ) {
                return false; // range value is in inactive range and not covered
            }
        }
        return true;
    }
};