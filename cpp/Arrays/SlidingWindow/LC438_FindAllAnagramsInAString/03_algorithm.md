Optimized Algorithm:
    - if p.length > s.length: return []
    - anagram_indices = []
    - required_frequencies = 0
    - build frequency map p_freq with string p and compute required_frequencies
    - matched_frequencies = 0
    - intialize fixed size window: left = 0, right = p.length - 1
    - build frequency map s_freq for string s with window [left, right] and compute matched_frequencies
    - if matched_frequencies == required_frequencies:
        - anagram_indices.push(left)
    - shift fixed size window: ++left, ++right
    - while right < s.length:
        - for leaving character:
            - if p_freq[s[left - 1]] > 0:
                - old_freq = s_freq[s[left - 1]]
                - new_freq = --s_freq[s[left - 1]]
                - req_freq = p_freq[s[left - 1]]
                - if old_freq == req_freq:
                    - --matched_frequencies
                - else if new_freq = req_freq:
                    - ++matched_frequencies
        - similarly, for entering character:
            - if p_freq[s[right]] > 0:
                - old_freq = s_freq[s[right]]
                - new_freq = ++s_freq[s[right]]
                - req_freq = p_freq[s[right]]
                - if old_freq == req_freq:
                    - --matched_frequencies
                - else if new_freq = req_freq:
                    - ++matched_frequencies

        - if matched_frequencies == required_frequencies:
            - anagram_indices.push(left)
        - shift fixed size window: ++left, ++right

    - return anagram_indices

Complexity:
    Time: O(m + n)
    Auxiliary Space: O(1), since characters are fixed lowercase english alphabets
    Total Space: O(n)         