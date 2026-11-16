class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(int n: nums) {
            ++freq[n];
        }
        int maxSubsequenceLength = 0;
        for(const auto& [n, f]: freq) {
            auto it = freq.find(n + 1);
            if(it != freq.end()) {
                maxSubsequenceLength = max(maxSubsequenceLength, f + it->second);
            }
        }
        return maxSubsequenceLength;
    }
};
