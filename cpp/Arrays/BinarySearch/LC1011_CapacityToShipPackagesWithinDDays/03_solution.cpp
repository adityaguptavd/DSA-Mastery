class Solution {
    bool canShip(vector<int>& weights, int days, int capacity) {
        int requiredDays = 1;
        int remaining_capacity = capacity;
        for(int w: weights) {
            if(remaining_capacity >= w) {
                remaining_capacity -= w;
            }
            else {
                ++requiredDays;
                remaining_capacity = capacity - w;
            }
        }
        return requiredDays <= days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        // maximum weights and sum of weights
        int max_weight = 0;
        int sum = 0;
        for(int w: weights) {
            sum += w;
            max_weight = max(max_weight, w);
        }
        // create boundaries for binary search
        int left = max_weight, right = sum;
        // apply binary search
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(canShip(weights, days, mid)) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        return left;
    }
};