Learning Journal:
    Input:
        - two strings s and t
        - not sorted lexically
        - cannot be empty
        - lowercase characters

    Output:
        - boolean (true/false)
        - single answer

    Constraints:
        1 <= s.length, t.length <= 5 * 10^4   --> O(nlogn) or O(n)
        s and t consist of lowercase English letters.

    Edge Cases:
        - string size mismatch between s and t
        - all characters are same in either s or t or both:
            e.g. s = "aaaa", t = "aaaa" or s = "aaaa", t = "bbbb"
        - both strings are same
        - both contains exactly one character

    Hidden Clues:
        - frequency of characters (will decide data structure based on information to store)

    Brute Force:
        - check if string length differs
        - if yes then return false, else
        - iterate over the s string character by character
        - for each character count number of characters in the s string and t string by iterating over each string
        - if both string has different counts then return false
        - else continue untill check for all characters in s string completes.
        - finally return true

    Repeated Work:
        - We are iterating the same characters again and again in both strings
        - We are counting same characters (if duplicates present) again and again in both strings

    Information to Remember:
        - If we store the current element we are iterating and it's frequency of appearing in the string, then we can just increment the frequency whenever we encounter a character and finally compare frequencies for characters in both strings
        - if any comparison is not equal just return false otherwise true
        - we can iterate both strings in one single pass simultaneously

    Pattern:
        - already seen? -> hashmap/hashset
        - already seen element mapping with their frequencies -> hashmap
        - hashset is discarded since we also have to store frequencies