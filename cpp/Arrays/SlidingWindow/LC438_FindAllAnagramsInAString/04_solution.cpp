class Solution {

    void updateFrequencies(const array<int, 26> &pattern_freq, array<int, 26> &window_freq, char key, int update_value, int& matched_frequencies) {
        int index = key - 'a';
        int old_freq = window_freq[index];
        window_freq[index] += update_value;
        int new_freq = window_freq[index];
        int req_freq = pattern_freq[index];
        if(req_freq > 0) {
            if(old_freq == req_freq) {
                --matched_frequencies;
            }
            else if(new_freq == req_freq) {
                ++matched_frequencies;
            }
        }
    }

public:
    vector<int> findAnagrams(string s, string p) {
        // create output array
        vector<int> anagram_indices;
        int m = static_cast<int>(p.size()), n = static_cast<int>(s.size());
        if(m > n) return anagram_indices;
        // initialize overall required frequencies
        int required_frequencies = 0;
        // build pattern freq map and compute required frequencies
        array<int, 26> pattern_freq = {0};
        for(char c: p) {
            if(++pattern_freq[c - 'a'] == 1) {
                ++required_frequencies;
            }
        }
        // initialize window
        int left = 0, right = m - 1;
        int matched_frequencies = 0;
        // build window_freq map and compute matched frequencies
        array<int, 26> window_freq = {0};
        for(int i = 0; i <= right; ++i) {
            updateFrequencies(pattern_freq, window_freq, s[i], 1, matched_frequencies);        
        }
        
        if(matched_frequencies == required_frequencies) {
            anagram_indices.push_back(left);
        }
        // shift the window
        ++left; ++right;
        while(right < n) {
            // update frequencies for leaving character
            updateFrequencies(pattern_freq, window_freq, s[left - 1], -1, matched_frequencies);
            // update frequencies for entering character
            updateFrequencies(pattern_freq, window_freq, s[right], 1, matched_frequencies);
            
            if(matched_frequencies == required_frequencies) {
                anagram_indices.push_back(left);
            }
            // shift the window
            ++left; ++right;
        }
        return anagram_indices;
    }
};