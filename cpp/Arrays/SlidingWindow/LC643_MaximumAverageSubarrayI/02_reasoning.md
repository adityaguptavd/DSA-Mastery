Learning Journal:
    Input:
        - an integer array nums
        - an integer k
    
    Output:
        - maximum average among all possible subarrays
        - float/double value
        - can be poitive, negative or zero
        - single answer

    Edge Cases:
        - all numbers are zeroes
        - k is exactly 1
        - k == nums.length
        - integer overflow after sum (we'll use long long)
        - division by 0 (not possible in this case since k >= 1)
        - multiple subarrays with same average
    
    Brute Force:
        - initialize max_sum = -infinity
        - for i = 0 to i <= n - k:
            - initialize current_sum = 0
            - for j = i to j <= i + k - 1:
                - current_sum += nums[j]
            - max_sum = max(max_sum, current_sum)
        - return max_sum / k

    Complexity:
        Time: O(nk), worst O(n^2)
        Space: O(1)

    Repeated Work:
        - calculating sum for most of the elements in each iteration which has already been considered
    
    Information to Remember:
        - If we already know the sum of iteration, then we just need to add the entering element and subtract the leaving element, that's it

    Pattern:
        - sliding window
