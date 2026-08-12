#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> diff(n + 1, 0);
        vector<int> answer(n, 0);
        for(const auto& booking: bookings) {
            int first_flight = booking[0];
            int last_flight = booking[1];
            int seats = booking[2];
            diff[first_flight - 1] += seats;
            diff[last_flight] -= seats;
        }
        int current = 0;
        for(int i = 0; i < n; ++i) {
            current += diff[i];
            answer[i] = current;
        }
        return answer;
    }
};