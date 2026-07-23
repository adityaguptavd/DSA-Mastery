Learning Journal:
    Input:
        - two strings s and t
        - not sorted lexically
        - valid ascii characters

    Output:
        - boolean (true/false)
        - single answer

    Constraints:
        1 <= s.length <= 5 * 10^4   --> O(n) or O(nlogn)
        t.length == s.length

    Edge Cases:
        - all characters are same in either s or t or both:
            e.g. s = "aaaa", t = "aaaa" or s = "aaaa", t = "bbbb"
        - both strings are same
        - both contains exactly one character

    Hidden Clues:
        - mapping of characters (will decide data structure based on information to store)

    Brute Force:
        - if length is 1, then return true (3rd edge case)
        - iterate string s
        - for ith character, iterate over s and t and check for every s[i] == s[j], t[i] == t[j].
        - if any case fails, return false
        - finally return true
    
    Complexity:
        Time: O(n^2)
        Space: O(1)

    Repeated Work:
        - We are iterating the same characters again and again in both strings
        - We are checking same characters (if duplicates present) again and again in both strings

    Information to Remember:
        - If we store character in s[i] -> t[i] and t[i] -> s[i] mapping, then we can simply check for future charcters whether they have same mapping as previous ones or not

    Pattern:
        - already seen element mapping with their corresponding replacement -> hashmap