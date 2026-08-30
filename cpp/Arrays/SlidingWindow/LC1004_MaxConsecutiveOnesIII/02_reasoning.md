Learning Journal:
    Input:
        - a binary array nums
        - an integer k
        - possible values are 0s and 1s
        - we can flip at most k 0s

    Output:
        - maximum number of consecutive 1s after flipping 0s

    Edge Cases:
        - no 0s are present
        - all values are 0s
        - nums.length == 1

    Brute Force:
        - intialize max_1s = 0
        - for i = 0 to n - 1:
            - maintain a zero_count = 0
            - for j = i to n - 1:
                - if nums[j] == 0:
                    ++zero_count
                - if zero_count > k:
                    - break
                - max_1s = max(max_1s, j - i + 1)
        - return max_1s

    Complexity:
        Time: O(n^2)
        Space: O(1)

    Repeated Work:
        - nums = [1, 1, 0, 0, 1, 0, 1], k = 1
        - after processing i = 0 and j = 2, we'll have counter = 0
        - so, at j = 3 when we encounter 0 again, the inner loop will terminate
        - now i = 1, j = 1 loop starts
        - here we are again gonna count from j = 1 to j = 3, which we have already counted in i = 0 loop.
        - This is the repeated work
    
    Information to Remember:
        - we can preserve information from j = 1 to j = 3 from previous loop and use it in next loop