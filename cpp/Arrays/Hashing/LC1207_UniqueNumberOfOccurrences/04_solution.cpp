#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>

using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, size_t> freq_map;
        unordered_set<size_t> freq_seen;
        for(int elem: arr) {
            ++freq_map[elem];
        }
        for(auto [elem, freq]: freq_map) {
            if(freq_seen.find(freq) != freq_seen.end()) {
                return false;
            }
            else {
                freq_seen.insert(freq);
            }
        }
        return true;
    }
};