#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() == 1) { // a/c to constraint s and t are of same size
            return true;
        }
        unordered_map<char, char> s_mp, t_mp;
        for(size_t i = 0; i < s.size(); i++) {
            auto s_it = s_mp.find(s[i]);
            auto t_it = t_mp.find(t[i]);
            if(s_it != s_mp.end() && t_it != t_mp.end()) {
                if(s_it->second != t[i] || t_it->second != s[i]) {
                    return false;
                }
            }
            else if(s_it == s_mp.end() && t_it == t_mp.end()) {
                s_mp.emplace(s[i], t[i]);
                t_mp.emplace(t[i], s[i]);
            }
            else {
                return false;
            }
        }
        return true;
    }
};