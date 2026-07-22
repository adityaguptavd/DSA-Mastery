// Optimized Algorithm 2
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
        // iterate string s and increment freq
        for(char c: s) {
            freq[c]++;
        }
        // iterate string t, decrement freq and if freq becomes less than 0 -> return false
        for(char c: t) {
            if(--freq[c] < 0) {
                return false;
            }
        }
        // since both strings are of same size and no negative freq found -> every frequency is already 0
        return true;
    }
};