class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        array<int, 26> freq = {};
        for(char c: magazine) {
            ++freq[c - 'a'];
        }
        for(char c: ransomNote) {
            if(freq[c - 'a'] == 0) {
                return false;
            }
            --freq[c - 'a'];
        }
        return true;
    }
};
