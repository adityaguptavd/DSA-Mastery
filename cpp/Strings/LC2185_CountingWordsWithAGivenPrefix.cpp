class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        for(const string& word: words) {
            bool isMatching = true;
            for(int i = 0; i < pref.size(); ++i) {
                if(word[i] != pref[i]) {
                    isMatching = false;
                    break;
                }
            }
            if(isMatching) ++count;
        }
        return count;
    }
};
