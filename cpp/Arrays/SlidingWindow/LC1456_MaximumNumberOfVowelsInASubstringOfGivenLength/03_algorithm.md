Optimized Algorithm:
    - initialize the window with left = 0, right = k - 1
    - calculate number of vowels in window [left, right] and store in current_vowel_count
    - intialize max_vowel_count = current_vowel_count
    - shift the window by one index: ++left, ++right
    - while right < n:
        - current_vowel_count = current_vowel_count - isVowel(s[left - 1]) + isVowel(s[right])
        - max_vowel_count = max(current_vowel_count, max_vowel_count)
        - ++left, ++right
    - return max_vowel_count

Complexity:
    Time: O(n + k) or O(n)
    Space: O(1)