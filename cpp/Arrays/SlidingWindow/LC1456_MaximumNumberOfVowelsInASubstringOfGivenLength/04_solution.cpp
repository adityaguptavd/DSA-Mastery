#include<iostream>
#include<string>

using namespace std;

class Solution {
    int isVowel(char c) {
        switch(c) {
            case 'a': case 'e': case 'i': case 'o': case 'u':
                return 1;
            default:
                return 0;
        }
    }
public:
    int maxVowels(string s, int k) {
        // initialize window of size k
        int left = 0, right = k - 1;
        // calculate number of vowels in current window
        int current_vowel_count = 0;
        for(int i = 0; i <= k - 1; ++i) {
            current_vowel_count += isVowel(s[i]);
        }
        // initialize max_vowel_count
        int max_vowel_count = current_vowel_count;
        // shift window towards right by 1 index
        ++left; ++right;
        int s_size = static_cast<int>(s.size());
        while(right < s_size) {
            // // calculate number of vowels in window after shift
            current_vowel_count = current_vowel_count - isVowel(s[left - 1]) + isVowel(s[right]);
            // update max vowel count
            max_vowel_count = max(max_vowel_count, current_vowel_count);
            // shift window towards right
            ++left; ++right;
        }
        return max_vowel_count;
    }
};