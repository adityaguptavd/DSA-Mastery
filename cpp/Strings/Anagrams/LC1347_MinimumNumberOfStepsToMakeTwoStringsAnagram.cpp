class Solution {
public:
    int minSteps(string s, string t) {
        array<int, 26> t_freq{};
        array<int, 26> s_freq{};
        for(char c: t) {
            ++t_freq[c - 'a'];
        }
        int steps = 0;
        for(char c: s) {
            if(++s_freq[c - 'a'] > t_freq[c - 'a']) {
                ++steps;
            }
        }
        return steps;
    }
};
