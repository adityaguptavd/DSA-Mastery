class Solution {
    int getOddCount(const vector<array<int, 26>> &prefixFreq, const vector<int> &query) {
        int l = query[0],
            r = query[1];
        int oddCount = 0;
        for(size_t i = 0; i < 26; ++i) {
            if((prefixFreq[r + 1][i] - prefixFreq[l][i]) % 2 != 0) {
                ++oddCount;
            }
        }
        return oddCount;
    }
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        size_t s_length = s.length();
        vector<array<int, 26>> prefixFreq(s_length + 1, array<int, 26>{});
        for(size_t i = 0; i < s_length; ++i) {
            prefixFreq[i + 1] = prefixFreq[i];
            ++prefixFreq[i + 1][s[i] - 'a'];
        }
        vector<bool> queryResult;
        for(const auto &query: queries) {
            int k = query[2];
            int oddCount = getOddCount(prefixFreq, query);
            queryResult.push_back((oddCount - 2 * k) <= 1);
        }
        return queryResult;
    }
};
