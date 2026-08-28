#include<string>
#include<array>

using namespace std;

class Solution {

public:
    int characterReplacement(string s, int k) {
        array<int, 26> freq_map = {0};
        int left = 0;
        int max_freq = 0;
        int max_length = 0;
        int n = static_cast<int>(s.size());
        for(int right = 0; right < n; ++right) {
            ++freq_map[s[right] - 'A'];
            max_freq = max(max_freq, freq_map[s[right] - 'A']);
            int window_size = right - left + 1;
            if(window_size - max_freq > k) {
                --freq_map[s[left] - 'A'];
                ++left;
            }
            max_length = max(max_length, right - left + 1);
        }
        return max_length;
    }
};