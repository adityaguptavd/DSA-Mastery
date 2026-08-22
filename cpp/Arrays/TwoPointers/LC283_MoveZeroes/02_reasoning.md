Learning Journal:
    Input:
        - an integer array nums
    
    Output:
        - move all the zeroes in the end of the array

    Edge Cases:
        - all elements are zeroes
        - all elements are non-zeroes
        - all zeroes are already at the end
        - all zeroes are at the beginning

    Brute Force:
        - for pass = 0 to n - 1
            - shifted = false
            - for i = 0 to n - 1
                - if nums[i] == 0:
                    - swap nums[i] with nums[i + 1]
                    - shifted = true
            - if not shifted:
                break

    Complexity:
        Time: O(n^2)
        Auxiliary Space: O(1)

    Repeated Work:
        - We are shifting one zero in one pass even though we are encountering every zero in that pass
        - Also we are shifting zero one position at a time

    Information to Remember:
        - What we can do is that we can track a first zero and non-zero postions where:
            zero's postion < non-zero's position
        - We'll swap them and them increment the tracker to track next non-zero and zero postions where:
            zero's postion < non-zero's position

    Pattern:
        - track two positions with conditions -> two pointers