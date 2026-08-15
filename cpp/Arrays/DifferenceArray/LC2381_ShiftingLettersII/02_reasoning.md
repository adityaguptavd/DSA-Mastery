Learning Journal:
    Input:
        - given string s of lowercase english alphabets
        - a 2D integer array shifts = [start, end, direction], end is inclusive
        - direction = 0 | 1, 0 -> backward shifting and 1 -> forward shifting
        - shifting a character forward means replacing with next character in the alphabet circularly (a -> b, e -> f, z -> a)
        - shifting a character backward means replacing with previous character in the alphabet circularly (b -> a, f -> e, a -> z)

    Output:
        - Apply all shifts and return final string

    Edge Cases:
        - current character is z in forward shift and a in backward shift
        - start == end
        - end == s.length - 1

    Brute Force:
        - for each [start, end, direction] in shifts:
            - replace characters from start to end (inclusive) with their preceding/succeeding (based on direction) characters in english alphabets
            - wrap the shifting in the range [a, z]
        - return updated string s

    Complexity:
        Time: O(s.length * shifts.length)
        Auxiliary Space: O(1)
        Total Space: O(s.length + shifts.length)

    Repeated Work:
        - we are repeatedly replacing overallaping character multiple times

    Information to Remember:
        - we can mark the locations where effect starts and where it ends
        - apply updates on those location marks and compute prefix sum to find effective updates for each index in effective range

    Pattern:
        - range updates/replacement + cumulative sum -> difference array + prefix sum