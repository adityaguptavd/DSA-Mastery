Optimized Algorithm:
    - if s1.length > s2.length: return false
    - build frequency map freq1 for s1 and while building calculate number of distinct characters in s1 and store in matches_required
    - intialize window of size s1.length in s2:
        - left = 0, right = s1.length - 1
    - initialize matches_found = 0
    - now build frequency map freq2 for window [left, right] in s2:
        - for i = 0 to right:
            - ++freq2[s2[i]]
            - if freq2[s2[i]] == freq1[s2[i]]:
                - ++matches_found
            - else if freq2[s2[i]] - 1 == freq1[s2[i]]:
                - --matches_found

    - ++right, ++left
    - while(right < s2.length && matches_found != matches_required):
        - --freq2[s2[left]], ++freq2[s2[right]]
        - if freq2[s2[left]] == freq1[s2[left]]:
            - ++matches_found
        - else if freq2[s2[left]] + 1 == freq1[s2[left]]:
            - --matches_found

        - if s2[left] != s2[right]:
            - if freq2[s2[right]] == freq1[s2[right]]:
                - ++matches_found
            - else if freq2[s2[right]] - 1 == freq1[s2[right]]:
                - --matches_found

        - ++left, ++right

    - return matches_found == matches_required

Complexity:
    Time: O(m + n)
    Space:
        - O(k), if we are using hashmaps
        - O(1), if using ascii array

    - where k is number of distinct elements in s1
    - m = s1.length
    - n = s2.length