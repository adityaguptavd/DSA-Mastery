#include<iostream>
#include<string>
#include<cctype>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int L = 0, R = static_cast<int>(s.size() - 1);
        while(L < R) {
            if(!isalnum(s[L])) {
                 ++L;
                 continue;
            }
            if(!isalnum(s[R])) {
                --R;
                continue;
            }
            if(tolower(s[L]) != tolower(s[R])) return false;
            ++L; --R;
        }
        return true;
    }
};