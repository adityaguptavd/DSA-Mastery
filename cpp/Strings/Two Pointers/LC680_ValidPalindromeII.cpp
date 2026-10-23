class Solution {
    // bool validPalindromeHelper(const string& s, int left, int right, bool deleted) {
        // if(left >= right) return true;
        // if(s[left] == s[right]) 
        //     return validPalindromeHelper(s, left + 1, right - 1, deleted);
        // if(deleted) return false;
        // bool left_deleted = validPalindromeHelper(s, left + 1, right, true);
        // bool right_deleted = validPalindromeHelper(s, left, right - 1, true);
        // return left_deleted || right_deleted;
    // }
    
    bool validPalindromeHelper(const string& s, int left, int right, bool deleted) {
        while(left < right) {
            if(s[left] == s[right]) {
                ++left; --right;
            }
            else {
                if(deleted) return false;
                else {
                    return validPalindromeHelper(s, left + 1, right, true) ||
                    validPalindromeHelper(s, left, right - 1, true);
                }
            }
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        return validPalindromeHelper(s, 0, s.size() - 1, false);
    }
};
