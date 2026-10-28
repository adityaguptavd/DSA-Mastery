class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int s_len = static_cast<int>(s.length());
        int word_len = static_cast<int>(words[0].length());
        int total_words = static_cast<int>(words.size());
        int window_size = word_len * total_words;
        if(s_len < window_size) return {};
        vector<int> starting_indices;
        unordered_map<string, int> words_freq;
        int matches_required = 0;
        for(const auto& word: words) {
            if(++words_freq[word] == 1) {
                ++matches_required;
            }
        }
        for(int offset = 0; offset < word_len && offset + window_size <= s_len; ++offset) {
            int matches_found = 0;
            unordered_map<string, int> window_freq;
            int left = offset, right = offset + window_size;
            for(int word_idx = left; word_idx < right; word_idx += word_len) {
                string word = s.substr(word_idx, word_len);
                int new_freq = ++window_freq[word];
                int old_freq = new_freq - 1;
                int req_freq = words_freq[word];
                if(req_freq > 0) {
                    if(req_freq == new_freq) {
                        ++matches_found;
                    }
                    else if(req_freq == old_freq) {
                        --matches_found;
                    }
                }
            }
            if(matches_found == matches_required) {
                starting_indices.push_back(left);
            }
            left += word_len;
            right += word_len;
            while(right <= s_len) {
                string leaving_word = s.substr(left - word_len, word_len);
                string entering_word = s.substr(right - word_len, word_len);

                int leaving_new_freq = --window_freq[leaving_word];
                int leaving_old_freq = leaving_new_freq + 1;
                int entering_new_freq = ++window_freq[entering_word];
                int entering_old_freq = entering_new_freq - 1;
                int leaving_req_freq = words_freq[leaving_word];
                int entering_req_freq = words_freq[entering_word];
                
                if(leaving_req_freq > 0) {
                    if(leaving_new_freq == leaving_req_freq) {
                        ++matches_found;
                    }
                    else if(leaving_old_freq == leaving_req_freq) {
                        --matches_found;
                    }
                }

                if(entering_req_freq > 0) {
                    if(entering_new_freq == entering_req_freq) {
                        ++matches_found;
                    }
                    else if(entering_old_freq == entering_req_freq) {
                        --matches_found;
                    }
                }

                if(matches_found == matches_required) {
                    starting_indices.push_back(left);
                }

                left += word_len;
                right += word_len;
            }
        }
        return starting_indices;
    }
};
