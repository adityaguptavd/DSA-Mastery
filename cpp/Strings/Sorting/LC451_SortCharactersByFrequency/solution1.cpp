class Solution {
public:
    string frequencySort(string s) {
        array<int, 75> freq = {};
        string distinct_chars, result;
        for(char c: s) {
            if(++freq[c - 48] == 1) {
                distinct_chars += c;
            }
        }
        auto compare = [&freq](char a, char b) -> bool {
            return freq[a - 48] > freq[b - 48];
        };
        sort(distinct_chars.begin(), distinct_chars.end(), compare);
        for(char c: distinct_chars) {
            for(int i = 0; i < freq[c - 48]; ++i) {
                result += c;
            }
        }
        return result;
    }
};
