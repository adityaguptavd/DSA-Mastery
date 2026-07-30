#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        if(s.size() == 1) return 0;
        // create hashmap
        unordered_map<char, int> freq;
        for(char c: s) {
            freq[c]++;
        }
        for(int i = 0; i < s.size(); ++i) {
            if(freq[s[i]] == 1) return i;
        }
        return -1;
    }
};