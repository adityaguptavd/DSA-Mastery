class Solution {
public:
    string reverseWords(string s) {
        int s_length = s.length();
        string reverse;
        // reverse string using two pointers
        int left = 0, right = s_length - 1;
        while(left < right) {
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            ++left; --right;
        }
        // reverse each word using two pointers
        left = 0;
        while(s[left] != '\0') {
            // replace trailing spaces with next word
            int replace_at = left;
            int next_word_at = left;
            while(s[next_word_at] != '\0' && s[next_word_at] == ' ') {
                ++next_word_at;
            }
            if(s[next_word_at] == '\0') break;
            if(replace_at > 0) {
                s[replace_at] = ' ';
                ++replace_at;
                ++left;
            }
            while(s[next_word_at] != '\0' && s[next_word_at] != ' ') {
                s[replace_at] = s[next_word_at];
                ++replace_at; ++next_word_at;
            }
            // find end of the word
            int right = replace_at - 1;
            while(left < right) {
                char temp = s[left];
                s[left] = s[right];
                s[right] = temp;
                ++left; --right;
            }
            // clear leftovers
            for(int i = replace_at; i < next_word_at; ++i) {
                s[i] = ' ';
            }
            left = replace_at;
        }
        s.resize(left);
        return s;
    }
};
