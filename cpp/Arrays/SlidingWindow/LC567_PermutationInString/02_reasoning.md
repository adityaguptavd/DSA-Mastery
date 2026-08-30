Learning Journal:
    Input:
        - two strings s1 and s2
        - s1 and s2 consists of lowercase english alphabets
    
    Output:
        - whether s2 contians permutation of s1 or not
        - in boolean type

    Edge Cases:
        - s1.length > s2.length
    
    Brute Force:
        - if s1.length > s2.length: return false
        - count frequencies freq1 of characters in s1
        - for i = 0 to n - s1.length:
            - for j = i to i + s1.length - 1:
                - maintain freq2 of each characters encountered
            - compare frequencies freq1 and freq2
            - if equal:
                - return true
        
        - return false

    Complexity:
        Time: O(m*n)
        Space:
            - using hashmap: O(n)
            - since characters are fixed lowercase english alphabets, we can use fixed size array: O(1)

    Repeated Work:
        - consecutive candidate windows have m - 1 characters in common
        - recalculating freq2 counts those shared characters again
        - when shifting the window by one position:
            - remove frequency of the leaving character
            - add frequency of the entering character
        - therefore, we can preserve the previous window's frequency information
