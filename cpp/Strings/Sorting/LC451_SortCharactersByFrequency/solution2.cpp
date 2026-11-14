class Solution {
public:
    string frequencySort(string s) {
        array<int, 75> freq = {};
        string result;
        vector<string> buckets(s.length() + 1);
        for(char c: s) {
            ++freq[c - 48];
        }
        for(int i = 0; i < 75; ++i) {
            if(freq[i] != 0) {
                buckets[freq[i]] += static_cast<char>(i + 48);
            }
        }
        for(int i = buckets.size() - 1; i > 0; --i) {
            string& bucket = buckets[i];
            for(char c: bucket) {
                for(int j = 0; j < i; ++j) {
                    result += c;
                }
            }
        }
        return result;
    }
};
