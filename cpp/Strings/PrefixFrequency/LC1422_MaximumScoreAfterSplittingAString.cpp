class Solution {
public:
    int maxScore(string s) {
        int total_ones = 0;
        int left_zeroes = 0;
        int left_ones = 0;
        int max_score = 0;
        size_t s_length = s.length();
        for(char c: s) {
            total_ones += (c - '0');
        }
        for(size_t split_index = 0; split_index <= s_length - 2; ++split_index) {
            if(s[split_index] == '0') {
                ++left_zeroes;
            }
            else {
                ++left_ones;
            }
            int right_ones = total_ones - left_ones;
            max_score = max(
                max_score,
                left_zeroes + right_ones
            );
        }
        return max_score;
    }
};
