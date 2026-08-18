#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int L = -1, R = static_cast<int>(s.size());
        while(++L < --R) {
            swap(s[L], s[R]);
        }
    }
};