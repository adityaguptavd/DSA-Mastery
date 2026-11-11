class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int length = static_cast<int>(s.size());
        int left = 0, right = 0;
        int curr_budget = 0;
        int max_length = 0;
        while(right < length) {
            curr_budget += abs(s[right] - t[right]);
            while(left <= right && curr_budget > maxCost) {
                curr_budget -= abs(s[left] - t[left]);
                ++left;
            }
            max_length = max(max_length, right - left + 1);
            ++right;
        }
        return max_length;
    }
};
