Learning Journal:
    Input:
        - a string pattern and a string s
        - pattern contains lowercase english letters
        - s contains lowercase english letters and spaces ' '
        - no leading/trailing spaces in s
        - words in s are separated by single space

    Output:
        - boolean value
        - single value

    Edge Cases:
        - both pattern and string s is exactly of size 1
        - string contains exactly one word
        - pattern contains same character (e.g., "aaaa")
        - string contains same words

    Brute Force:
        - split the given string at spaces into array of strings (for simplicity) -> O(n)
        - now scan both pattern and string simultaneously
        - for ith iteraction: -> O(n)
            - find pattern[i] and words[i]
            - now search the whole pattern string and words array and check: -> O(n)
                - if pattern[i] == pattern[j] && words[i] == words[j], then continue
                - else return false
        - finally return true
    
    Complexity:
        Time: O(n^2 + n), where n is length of string s
        Space: O(n), for storing strings as array

    Constraints:
        - 1 <= pattern.length <= 300
        - pattern contains only lower-case English letters.
        - 1 <= s.length <= 3000
        - s contains only lowercase English letters and spaces ' '.
        - s does not contain any leading or trailing spaces.
        - All the words in s are separated by a single space.
        - So, O(n^2) is acceptable, but we have room for optimizations
    
    Repeated Work:
        - Iterating same character in pattern and word in string for each character in pattern to find corresponding one-to-one mapping, since one character is mapped to only one word and vice versa

    Information to Remember:
        - while iterating over each character in pattern, we can store its corresponding one-to-one mapping with word in string -> O(n)
        - if mapping already exists, then validate the current mapping with stored mapping -> O(1)
        - if invalidates, then return false, else continue -> O(1)

    Complexity:
        Time: O(n)
        Space: - We have already solved a problem of one-to-one mapping and we required two hashmaps.
        - So space complexity will be O(k), where k is the number of distinct character in pattern and string combined.

    Pattern:
        - One to One mapping with bidirectional checking -> Two HashMaps