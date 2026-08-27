Learning Journal:
    Input:
        - an array of positive integers nums
        - a positive integer target
    
    Output:
        - minimal length of a subarray whose sum is greater than or equal to target
        - there is no such subarray, return 0 instead

    Edge Cases:
        - nums.length = 1
        - no subarray exists with sum >= target
        - multiple subarray exists with sum >= target
    
    Brute Force:
        - initialize min_size = +infinity
        - for i = 0 to n - 1:
            - current_sum = 0
            - for j = i to n - 1:
                - current_sum += nums[j]
                - if current_sum >= target:
                    - min_size = min(min_size, j - i + 1)
                    - break
        - return min_size == +infinity ? 0: min_size

    Complexity:
        Time: O(n^2)
        Space: O(1)