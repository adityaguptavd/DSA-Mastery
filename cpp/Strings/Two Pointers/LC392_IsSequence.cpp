class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.size() == 0) return true;
        if(s.size() > t.size()) return false;
        int curr = 0, curr_s = 0;
        while(curr < t.size() && curr_s < s.size()) {
            if(s[curr_s] == t[curr]) {
                ++curr_s;
            }
            ++curr;
        }
        return curr_s == s.size();
    }
};
