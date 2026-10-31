class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int order_len = static_cast<int>(order.length());
        int total_words = static_cast<int>(words.size());
        array<int, 26> rank{};
        for(int i = 0; i < order_len; ++i) {
            rank[order[i] - 'a'] = i;
        }
        for(int i = 0; i < total_words - 1; ++i) {
            string curr_word = words[i];
            string next_word = words[i + 1];
            int curr_word_len = static_cast<int>(curr_word.length());
            int next_word_len = static_cast<int>(next_word.length());
            int smaller_len = min(curr_word_len, next_word_len);
            bool is_same_prefix = true;
            for(int j = 0; j < smaller_len; ++j) {
                if(rank[curr_word[j] - 'a'] > rank[next_word[j] - 'a']) {
                    return false;
                }
                else if(rank[curr_word[j] - 'a'] < rank[next_word[j] - 'a']) {
                    is_same_prefix = false;
                    break;
                }
            }
            if(
                is_same_prefix &&
                (curr_word_len != next_word_len) &&
                (smaller_len == next_word_len)
            ) {
                return false;
            }
        }
        return true;
    }
};
