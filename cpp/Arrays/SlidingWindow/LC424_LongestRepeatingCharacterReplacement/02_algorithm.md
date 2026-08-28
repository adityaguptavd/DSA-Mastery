Optimized Algorithm:
    - given string s and integer k
    - initialize freq hashmap or we can also use an array since characters are limited to upper case english alphabets
    - initialize left = 0
    - max_freq = 0
    - for right = 0 to n - 1:
        - ++freq[s[right]]
        - max_freq = max(max_freq, freq[s[right]])
        - win_len = right - left + 1
        - if win_len - max_freq > k:
            - --freq[s[left]]
            - ++left
    - return max_freq + k

Complexity:
    Time: O(n)
    Space: O(m), where m is number of distinct elements in s