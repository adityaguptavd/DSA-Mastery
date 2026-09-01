Learning Journal:
    Input:
        - two strings s and t of lengths m and n respectively
        - duplicates present
        - s and t consist of uppercase and lowercase English letters.

    Output:
        - return the minimum window substring of s such that every character in t (including duplicates) is included in the window
        - empty string "", if no such substring present
        - answer is unique

    Edge Cases:
        - n > m
        - n == m
        - case sensitive
        - no required substring present
    
    Brute Force:
        - if n > m:
            - return ""
        - min_win = ""
        - build frequency map pattern_freq for string t
        - for i = 0 to m - 1:
            - intialize window_freq
            - for j = i to m - 1:
                - ++window_freq[j]
                - check if frequency of each character in pattern_freq <= frequency of corresponding character in window_freq
                - if yes:  
                    - min_win = min_win.length < (j - i + 1) ? min_win: substring s[i, j]
                    - break

        - return min_win
                
    Complexity:
        Time: O(m * m)
        Space: O(1), since characters are fixed uppercase and lowercase english alphabets

    Repeated Work:
        - for the first iteration, we have build frequency for substring s[0, k]
        - in second iteration, we are building frequency for substring s[1, k + 1]
        - here substring s[1, k] is common in both iteration and we are recalculating frequency for this substring again

    Information to Remember::
        - we can carry this frequency information to next iteration
        - remove the contribution of leaving entity and add the contribution of entering entity to that information
    
    Pattern:
        - maintaining information for a range of elements and carrying that information to next iteration -> sliding window