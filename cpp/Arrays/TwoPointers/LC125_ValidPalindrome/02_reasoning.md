Learning Journal:
    Input:
        - a string s
    
    Output:
        - return true, if s is palindrome after removing non-alphanumeric characters and converting all alphanumeric characters into lowercase
        - else return false

    Edge Cases:
        - empty string
        - all non-alphanumeric characters
        - lowercase vs uppercase
        - contains exactly one character
    
    Brute Force:
        - remove non-alphanumeric characters - TC(n)
        - convert to lowercase - TC(n)
        - reverse the string - TC(n), SC(n)
        - compare character by character - TC(n)
        - if equal return true
        - else false

    Complexity:
        Time: O(n)
        Space: O(n)

    Repeated Work:
        - We are iterating same character again and again to remove, convert, reverse and compare.
        - This means we are visiting each character 4 times.

    Information to Remember:
        - We need to do all the above operations in one pass
        - Instead of iterating from one side, we can start from both edges to inwards
        - While iterating, we'll validate(skip/convert to lowercase) the current character, if eligible then compare with each other
        - If any doesn't match return false
        - after loop ends, return true