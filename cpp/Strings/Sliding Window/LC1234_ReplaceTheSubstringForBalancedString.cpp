class Solution {
    int get_index(char c) {
        switch(c) {
            case 'Q':
                return 0;
            case 'W':
                return 1;
            case 'E':
                return 2;
            case 'R':
                return 3;
            default:
                return -1;
        }
    }
public:
    int balancedString(string s) {
        int s_len = static_cast<int>(s.size());
        array<int, 4> win_freq = {};
        array<int, 4> outside_freq = {};
        int req_freq = s_len / 4;
        int outside_invalid_freq = 0;
        for(char c: s) {
            if(++outside_freq[get_index(c)] == req_freq + 1) {
                ++outside_invalid_freq;
            }
        }
        if(outside_invalid_freq == 0) return 0;
        int minimum_replaceable_substring_length = numeric_limits<int>::max();
        int left = 0, right = 0;
        while(right < s_len) {
            if(--outside_freq[get_index(s[right])] == req_freq) {
                --outside_invalid_freq;
            }
            while(left <= right && outside_invalid_freq == 0) {
                minimum_replaceable_substring_length = min(
                    minimum_replaceable_substring_length,
                    right - left + 1
                );
                if(++outside_freq[get_index(s[left])] == req_freq + 1) {
                    ++outside_invalid_freq;
                }
                ++left;
            }
            ++right;
        }
        return minimum_replaceable_substring_length == numeric_limits<int>::max()
        ? 0
        : minimum_replaceable_substring_length;
    }
};
