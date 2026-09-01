Optimized Algorithm:
    - min_win_left = 0
    - min_win_right = -1 // net length = -1
    - if n > m: return ""
    - initialize pattern_freq, window_freq maps
    - initialize required_frequencies = 0 and matched_frequencies = 0
    - build pattern_freq and compute required_frequencies
    - initialize window's left boundary: left = 0
    - initialize and expand window's right boundary:
        - for right = 0 to m - 1:
            - new_freq = ++window_freq[s[right]]
            - required_freq = pattern_freq[s[right]]
            - if required_freq > 0:
                - if new_freq == required_freq:
                    - ++matched_frequencies
            - if matched_frequencies >= required_frequencies:
                - if (min_win_right - min_win_left) > (right - left):
                    - min_win_left = left, min_win_right = right
                - shrink the window aggresively:
                    - while left < right:
                        - remove the contribution of leaving character
                            - old_freq = window_freq[s[left]]--
                            - required_freq = pattern_freq[s[left]]
                            - ++left
                            - if required_freq > 0:
                                - if old_freq == required_freq:
                                    - --matched_frequencies
                            - if matched_frequencies >= required_frequencies:
                                - if (min_win_right - min_win_left) > (right - left):
                                    - min_win_left = left, min_win_right = right
                            - else:
                                - break
    - return substring s[min_win_left, min_win_right]
            

Complexity:
    Time: O(m + n)
    Auxiliary Space: O(1), since characters are fixed lowercase and uppercase english alphabets