class Solution {
public:
    string reverseWords(string s) {
        string reverse;
        int i = s.length() - 1;
        while(i >= 0) {
            // skip trailing spaces
            while(i >= 0 && s[i] == ' ') {
                --i;
            }
            // mark current index as end of the word and find for start index
            int end = i;
            while(i >= 0 && s[i] != ' ') {
                --i;
            }
            // construct word
            string word;
            for(int j = i + 1; j <= end; ++j) {
                word += s[j];
            }
            if(!word.empty()) {
                // append to reverse
                if(reverse.empty()) {
                    reverse = word;
                }
                else {
                    reverse = reverse + ' ' + word;
                }
            }
        }
        return reverse;
    }
};
