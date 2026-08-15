#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
    int normalize_value(int value, int left, int right, int increment_value = 0) {
        int range = (right - left + 1);
        int value_to_normalize = value + increment_value - left;
        return left + (((value_to_normalize % range) + range) % range);
    }
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int> net_shift(s.size() + 1, 0);
        for(const auto& shift: shifts) {
            int start = shift[0];
            int end = shift[1];
            int dir = shift[2];
            int shift_value = (dir == 0) ? -1: +1;
            net_shift[start] += shift_value;
            net_shift[end + 1] -= shift_value;
        }
        int current_net_shift = 0;
        for(int i = 0; i < s.size(); ++i) {
            current_net_shift += net_shift[i];
            s[i] = static_cast<char>(normalize_value(s[i], 'a', 'z', current_net_shift));
        }
        return s;
    }
};