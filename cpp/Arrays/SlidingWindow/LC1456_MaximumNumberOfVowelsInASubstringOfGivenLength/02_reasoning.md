Learning Journal:
    Brute Force:
        - intialize max_vowel_count = 0
        - for i = 0 to n - k:
            - current_vowel_count = 0
            - for j = i to i + k - 1:
                - if s[j] is a vowel:
                    - ++current_vowel_count
            - max_vowel_count = max(max_vowel_count, current_vowel_count)
        - return max_vowel_count

    Complexity:
        Time: O(nk)
        Space: O(1)

    Repeated Work:
        - here for i = 0:
            - we are counting vowels from 0 to k - 1
        - and for i = 1:
            - we are counting vowels from 1 to k
        - and so on.
        - we have calculated vowels from 1 to k - 1 twice for i = 0 and 1
        - same goes for rest of the iteration

    Information to Remember:
        - for i = 0, we already know number of vowels from 0 to k - 1
        - for i = 1, we need to find number of vowels from 1 to k
        - which means excluding vowel at 0 and including vowel at k (if vowel exists at those locations)