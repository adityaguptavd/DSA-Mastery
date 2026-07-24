#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // create anagram groups array
        vector<vector<string>> anagram_groups;
        // create hashmap
        unordered_map<string, size_t> group_index_map;
        // iterate over strs
        for(const string &curr_str: strs) {
            // copy current string and then sort the copied string to make it key
            string key_str = curr_str;
            sort(key_str.begin(), key_str.end());
            // check key existence in group_index_map
            auto it = group_index_map.find(key_str);
            if(it == group_index_map.end()) {
                group_index_map.emplace(key_str, anagram_groups.size());
                anagram_groups.push_back({ curr_str });
            }
            else {
                anagram_groups[it->second].push_back(curr_str);
            }
        }
        return anagram_groups;
    }
};