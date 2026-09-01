class Solution {
    void updateFrequencies(const array<int, 58> &pattern_freq, array<int, 58> &window_freq, char key, int& matched_frequencies, bool removing = false) {
        int index = key - 'A';
        int old_freq = window_freq[index];
        window_freq[index] += !removing ? 1: -1;
        int new_freq = window_freq[index];
        int required_freq = pattern_freq[index];

        if(required_freq > 0) {
            if(!removing && new_freq == required_freq) {
                ++matched_frequencies;
            }
            else if(removing && old_freq == required_freq) {
                --matched_frequencies;
            }
        }
    }
    void updateMinWindow(int &min_win_left, int &min_win_right, int left, int right) {
        if(min_win_right == -1 || (min_win_right - min_win_left) > (right - left)) {
            min_win_left = left;
            min_win_right = right;
        }
    }
public:
    string minWindow(string s, string t) {
        int n = static_cast<int>(t.size()), m = static_cast<int>(s.size());
        if(n > m) return "";

        int min_win_left = 0;
        int min_win_right = -1;
        // initialize pattern_freq, window_freq maps size 58 -> 'A' to 'z'
        array<int, 58> pattern_freq = {0}, window_freq = {0};
        // initialize required_frequencies = 0 and matched_frequencies = 0
        int required_frequencies = 0, matched_frequencies = 0;
        // build pattern_freq and compute required_frequencies
        for(char c: t) {
            if(++pattern_freq[c - 'A'] == 1) {
                ++required_frequencies;
            }
        }
        // initialize window's left boundary: left = 0
        int left = 0;
        // initialize and expand window's right boundary
        for(int right = 0; right < m; ++right) {
            // update frequencies by adding contribution of entering character
            updateFrequencies(pattern_freq, window_freq, s[right], matched_frequencies);
            if(matched_frequencies >= required_frequencies) {
                updateMinWindow(min_win_left, min_win_right, left, right);
                // shrink the window aggresively
                while(left < right) {
                    // remove the contribution of leaving character
                    updateFrequencies(pattern_freq, window_freq, s[left], matched_frequencies, true);
                    ++left;
                    if(matched_frequencies >= required_frequencies) {
                        updateMinWindow(min_win_left, min_win_right, left, right);
                    }
                    else {
                        break;
                    }
                }
            }
        }
        return s.substr(min_win_left, min_win_right - min_win_left + 1);
    }
};