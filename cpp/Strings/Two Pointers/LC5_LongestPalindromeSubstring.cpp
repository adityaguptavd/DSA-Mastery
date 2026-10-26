class Solution {
    // minimum palindrome length: 1
    int longest_palindrome_start = 0;
    int longest_palindrome_end = 0; // inclusive

    void updateLongestPalindromeAtCenter(const string& s, int left, int right) {
        while(
            left >= 0 &&
            right < s.size() &&
            s[left] == s[right]
        ) {
            --left; ++right;
        }
        ++left; --right;
        if(
            (right - left) > (longest_palindrome_end - longest_palindrome_start)
        ) {
            longest_palindrome_start = left;
            longest_palindrome_end = right;
        }
    }
public:
    string longestPalindrome(string s) {
        for(int i = 0; i < s.size(); ++i) {
            updateLongestPalindromeAtCenter(s, i, i);
            updateLongestPalindromeAtCenter(s, i, i + 1);
        }
        return s.substr(longest_palindrome_start, longest_palindrome_end - longest_palindrome_start + 1);
    }
};
