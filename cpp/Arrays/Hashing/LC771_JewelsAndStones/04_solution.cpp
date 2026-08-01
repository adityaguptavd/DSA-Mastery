#include<iostream>
#include<string>
#include<unordered_set>

using namespace std;

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int counter = 0;
        unordered_set<char> jewels_seen;
        // build hashset
        for(char j: jewels) {
            jewels_seen.insert(j);
        }

        // count stones that are jewels
        for(char s: stones) {
            if(jewels_seen.find(s) != jewels_seen.end()) {
                ++counter;
            }
        }
        return counter;
    }
};