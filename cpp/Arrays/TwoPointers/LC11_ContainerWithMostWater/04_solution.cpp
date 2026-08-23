#include<iostream>
#include<vector>
#include<climits>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        // create two pointers
        int L = 0, R = height.size() - 1;
        int max_water_volume = 0;
        while(L < R) {
            int current_water_volume = min(height[L], height[R]) * (R - L);
            max_water_volume = max(max_water_volume, current_water_volume);
            if(height[L] < height[R]) ++L;
            else --R;
        }
        return max_water_volume;
    }
};