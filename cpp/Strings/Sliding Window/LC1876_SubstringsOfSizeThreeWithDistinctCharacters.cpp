class Solution {
public:
    int countGoodSubstrings(string s) {
        int s_len = static_cast<int>(s.size());
        if(s_len < 3) return 0; 
        array<int, 26> is_exist = {};
        int left = 0, right = 0;
        int duplicate_count = 0;
        for(; right < 3; ++right) {
            if(++is_exist[s[right] - 'a'] == 2) {
                ++duplicate_count;
            }
        }
        int good_substrings = duplicate_count == 0 ? 1: 0;
        ++left;
        while(right < s_len) {
            int leaving_freq = --is_exist[s[left - 1] - 'a'];
            int entering_freq = ++is_exist[s[right] - 'a'];
            if(leaving_freq == 1) {
                --duplicate_count;
            }
            if(entering_freq == 2) {
                ++duplicate_count;
            }
            if(duplicate_count == 0) {
                ++good_substrings;
            }
            ++left; ++right;
        }
        return good_substrings;
    }
};
