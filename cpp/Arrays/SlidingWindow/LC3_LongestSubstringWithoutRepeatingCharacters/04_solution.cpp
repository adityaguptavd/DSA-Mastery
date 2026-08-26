#include<string>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        size_t n = s.size();
        if(n == 0) return 0;
        // create hashmap and left pointer
        unordered_map<char, size_t> seen;
        size_t left = 0;
        // initialize max
        int max_size = 0;
        for(size_t right = 0; right < n; ++right) {
            // check for duplicate character in current window
            auto entry = seen.find();
            if(entry != end && entry->second >= left) {
                left = entry->second + 1;
            }
            // update seen value
            seen[s[right]] = right;
            max_size = max(max_size, right - left + 1);
        }
        return max_size;
    }
};