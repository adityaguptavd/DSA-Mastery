Learning Journal:
    Input:
        - two strings jewels and stones
        - contains english letters

    Output:
        - number of stones that are jewels
        - non-negative integer value
        - single value

    Edge Cases:
        - stone and jewels are exactly of one size
        - jewels = "z", stones = "zZ"
        - no stones is jewels
        - all stones is jewels
        - all jewels is in stones
        
    Brute Force:
        - for each jewel in jewels:
            - count its occurrences in stones
            - add in total count
        - finally return total count

    Complexity:
        Time: O(m * n)
        Space: O(1)

    Constraints:
        - 1 <= jewels.length, stones.length <= 50
        - jewels and stones consist of only English letters.
        - All the characters of jewels are unique.
        - This time complexity is acceptable but we still have room for optimization
    
    Repeated Work:
        - we are continuously comparing each character of stones with jewels again and again

    Information to Remember:
        - if we somehow already know that this character is a jewel, then we can just count it in stones

    Pattern:
        - already seen -> hashset