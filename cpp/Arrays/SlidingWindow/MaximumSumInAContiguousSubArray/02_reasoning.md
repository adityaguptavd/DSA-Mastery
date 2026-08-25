Learning Journal:
    Input:
        - an array of numbers
        - an integer k

    Output:
        - maximum sum of any contiguous subarray of exactly k elements

    Edge Cases:
        - all values are negative
        - all values are zero
        - k = 1
        - k is exactly equal to array size
        - k > array size (depending on problem constraint)

    Brute Force:
        - initialize max_sum = -infinity
        - for i = 0 to n - k:
            - initialize sum = 0
            - for j = i to i + k - 1:
                - sum += arr[j]
            - max_sum = max(max_sum, sum)

        - return max_sum

    Complexity:
        Time: O(nk), in worst case O(n^2)
        Space: O(1)

    Repeated Work:
        - notice in first iteration we have calculated sum from i = 0 to k - 1 and in second iteration we have calculated sum from i = 1 to k.
        - we have calculated sum from i = 1 to i = n - k two times in only two iterations. 
        - Similarly for others as well

    Information to Remember:
        - Whenever i is increased, the value at i-1 leaves and i + k - 1 enters
        - So the new sum = old sum - (value at i-1) + (value at i + k - 1)
        - Hence we need to iterate to calculate sum

    Pattern:
        - A value maintained in a contiguous range -> sliding window