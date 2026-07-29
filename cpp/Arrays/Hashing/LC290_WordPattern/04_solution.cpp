#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
    vector<string> split(const string& s) {
        vector<string> split_result;
        string interim_result = "";
        for(const char c: s) {
            if(c != ' ') interim_result += c;
            else {
                split_result.push_back(interim_result);
                interim_result = "";
            }
        }
        // last word
        split_result.push_back(interim_result);
        return split_result;
    }
public:
    bool wordPattern(string pattern, string s) {
        // split string s into words
        vector<string> words = split(s);
        if(words.size() != pattern.size()) return false;
        if(pattern.size() == 1) return true; // optional

        // create hashmaps
        unordered_map<char, string> pattern_to_word;
        unordered_map<string, char> word_to_pattern;

        // iterate over pattern
        for(size_t i = 0; i < pattern.size(); ++i) {
            auto pattern_it = pattern_to_word.find(pattern[i]);
            auto word_it = word_to_pattern.find(words[i]);
            if(pattern_it == pattern_to_word.end() && word_it == word_to_pattern.end()) {
                pattern_to_word.emplace(pattern[i], words[i]);
                word_to_pattern.emplace(words[i], pattern[i]);
            }
            else if(pattern_it != pattern_to_word.end() && word_it != word_to_pattern.end()) {
                if(pattern_it->second != words[i] || word_it->second != pattern[i]) return false;
            }
            // invalid entry/mapping in HashMaps if exactly one doesn't exist in map
            else return false;
        }
        return true;
    }
};