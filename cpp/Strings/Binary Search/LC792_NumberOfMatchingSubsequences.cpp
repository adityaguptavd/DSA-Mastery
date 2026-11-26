class Solution {
    int findSmallestIndexGreaterThanKey(const vector<int> &indices, int key) {
        int total_indices = static_cast<int>(indices.size());
        int low = 0, high = total_indices;
        while(low < high) {
            int mid = low + (high - low) / 2;
            if(indices[mid] <= key) {
                low = mid + 1;
            }
            else if(indices[mid] > key) {
                high = mid;
            }
        }
        return high == total_indices ? -1: indices[high];
    }
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<char, vector<int>> freq;
        int s_len = static_cast<int>(s.size());
        for(int i = 0; i < s_len; ++i) {
            freq[s[i]].push_back(i);
        }
        int num_matching_subseq = 0;
        for(const auto& word: words) {
            int last_char_index = -1;
            bool is_valid_subseq = true;
            for(char c: word) {
                int curr_char_smallest_index = findSmallestIndexGreaterThanKey(
                    freq[c],
                    last_char_index
                );
                if(curr_char_smallest_index == -1) {
                    is_valid_subseq = false;
                    break;
                }
                last_char_index = curr_char_smallest_index;
            }
            if(is_valid_subseq) {
                ++num_matching_subseq;
            }
        }
        return num_matching_subseq;
    }
};
