Learning Journal:
    Input:
        - two strings s and p
        - s and p consists of lowercase english letters

    Output:
        - an array of all the start indices of p's anagrams in s

    Edge Cases:
        - p.length > s.length
        - no anagrams present
        - p.length == 1
    
    Brute Force:
        - if p.length > s.length: return []
        - create frequency map freq1 for string p
        - anagram_indices = []
        - for i = 0 to s.length - 1:
            - build frequency map freq2 for substring s[i, i + p.length - 1]
            - compare both frequencies:
                - if equal, store i in anagram_indices
        - return anagram_indices

    Complexity:
        Time: O(s.length * p.length) | O(s.length ^ 2) in worst case
        Auxiliary Space: O(1)
        Total Space (incl. of output): O(s.length) in worst case

    Repeated Work:
        - when calculating frequency for substring s[i, i + p.length - 1] for i > 0, we have already calculated frequency for substring s[i, i + p.length - 2] in previous iteration
    
    Information to Remember:
        - we can preserve or carry those frequencies in next iteration
        - we can maintain frequencies over the substring range s[i, i + p.length - 1] and during iteration movement, we can reduce the frequency of leaving character and add the entering character

    Pattern:
        - maintaining information over a range during multiple iterations -> sliding window