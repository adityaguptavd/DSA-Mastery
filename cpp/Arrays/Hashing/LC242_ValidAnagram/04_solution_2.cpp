// Optimized Algorithm 3
#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        // if both string's length is not equal -> false
        if(s.size() != t.size()) return false;
        // create hashmap
        unordered_map<char, int> freq;
        // iterate string s and t and increment and decrement freq respectively
        for(int i = 0; i < s.size(); i++) {
            freq[s[i]]++;
            freq[t[i]]--;
        }
        // check if all frequencies become 0 or not
        for(auto [c, f]: freq) {
            if(f) return false;
        }
        return true;
    }
};