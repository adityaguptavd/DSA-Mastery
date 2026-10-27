class Solution {
    int countSubstringsWithCenter(const string &s, int left, int right) {
        int s_len = static_cast<int>(s.length());
        int num_palindromic_substr = 0;
        while(
            left >= 0 &&
            right < s_len &&
            s[left] == s[right]
        ) {
            ++num_palindromic_substr;
            --left; ++right;
        }
        return num_palindromic_substr;
    }
public:
    int countSubstrings(string s) {
        int s_len = static_cast<int>(s.length());
        int num_palindromic_substr = 0;
        for(int i = 0; i < s_len; ++i) {
            num_palindromic_substr += countSubstringsWithCenter(s, i, i);
            num_palindromic_substr += countSubstringsWithCenter(s, i, i + 1);
        }
        return num_palindromic_substr;
    }
};
