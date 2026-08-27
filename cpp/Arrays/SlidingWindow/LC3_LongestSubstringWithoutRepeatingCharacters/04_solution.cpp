class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = static_cast<int>(s.size());
        if(n == 0) return 0;
        // create hashmap and left pointer
        unordered_map<char, int> seen;
        int left = 0;
        // initialize max
        int max_size = 0;
        for(int right = 0; right < n; ++right) {
            // check for duplicate character in current window
            auto entry = seen.find(s[right]);
            if(entry != seen.end() && entry->second >= left) {
                left = entry->second + 1;
            }
            // update seen value
            seen[s[right]] = right;
            max_size = max(max_size, right - left + 1);
        }
        return max_size;
    }
};
