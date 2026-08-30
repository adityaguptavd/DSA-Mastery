class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        // build frequency map for s1
        array<int, 26> freq1 = {0};
        int matches_required = 0;
        for(char c: s1) {
            size_t index = c - 'a';
            if(++freq1[index] == 1) {
                ++matches_required;
            }
        }
        // initialize window for s2
        size_t left = 0, right = s1.size() - 1;
        int matches_found = 0;
        // build frequency map for window in s2
        array<int, 26> freq2 = {0};
        for(size_t i = 0; i <= right; ++i) {
            size_t index = s2[i] - 'a';
            int old_freq = freq2[index];
            int new_freq = ++freq2[index];
            int s1_freq = freq1[index];
            if(s1_freq > 0) {
                if(old_freq == s1_freq) {
                    --matches_found;
                }
                else if(new_freq == s1_freq) {
                    ++matches_found;
                }
            }
        }
        if(matches_found == matches_required) {
            return true;
        }
        // shift window
        ++left; ++right;
        size_t n = s2.size();
        while(right < n) {
            size_t leaving_char_index = s2[left - 1] - 'a';
            size_t entering_char_index = s2[right] - 'a';

            int leaving_char_old_freq = freq2[leaving_char_index];
            int leaving_char_new_freq = --freq2[leaving_char_index];
            int leaving_char_freq_s1 = freq1[leaving_char_index];

            int entering_char_old_freq = freq2[entering_char_index];
            int entering_char_new_freq = ++freq2[entering_char_index];
            int entering_char_freq_s1 = freq1[entering_char_index];

            if(leaving_char_freq_s1 > 0) {
                if(leaving_char_old_freq == leaving_char_freq_s1) {
                    --matches_found;
                }
    
                else if(leaving_char_new_freq == leaving_char_freq_s1) {
                    ++matches_found;
                }
            }

            if(entering_char_freq_s1 > 0) {
                if(entering_char_old_freq == entering_char_freq_s1) {
                    --matches_found;
                }
    
                else if(entering_char_new_freq == entering_char_freq_s1) {
                    ++matches_found;
                }
            }


            if(matches_found == matches_required) {
                return true;
            }

            ++left; ++right;
        }
        return false;
    }
};