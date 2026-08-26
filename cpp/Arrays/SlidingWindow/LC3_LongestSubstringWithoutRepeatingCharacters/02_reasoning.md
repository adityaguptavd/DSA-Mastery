Learning Journal:
    Input:
        - a string s
        - s consists of English letters, digits, symbols and spaces.

    Output:
        - length of the longest substring without duplicate characters

    Edge Cases:
        - no duplicates present
        - s.length == 0 or 1
        - case sensitive
    
    Brute Force:
        - initialize max_size = 0
        - n = s.length
        - for i = 0 to i < n:
            - create empty hashset
            - for j = i to j < n:
                - if s[j] exists in hashset:
                    - break
                - add entry in hashset for s[j]
                - max_size = max(max_size, j - i + 1)
        - return max_size

    Complexity:
        Time: O(n^2)
        Auxiliary Space: O(n)

    Repeated Work:
        - while calculating for i = 0, let's say we have reached till i = 5 and encountered duplicate.
        - now after reseting and updating max, we are starting from i = 1
        - we are recalculating distinct elements from i = 1 onwards

    Information to Remember:
        - While moving to next iteration if we somehow maintain the number of distinct characters from previous iteration, then it would help in avoiding unnecessary recalculation

    Pattern:
        - Sliding Window + Hashmap