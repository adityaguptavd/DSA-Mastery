#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> diff(1001, 0);
        for(const auto& trip: trips) {
            int passengers = trip[0];
            int from = trip[1];
            int to = trip[2];
            diff[from] += passengers;
            diff[to] -= passengers;
        }
        int num_of_passengers = 0;
        for(const int d: diff) {
            num_of_passengers += d;
            if(num_of_passengers > capacity) return false;
        }
        return true;
    }
};