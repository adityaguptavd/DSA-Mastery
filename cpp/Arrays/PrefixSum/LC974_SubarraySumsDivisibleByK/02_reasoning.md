Learning Journal:
    Input:
        - An array of integers nums
        - an integer k
        - non-empty array nums
        - minimum value of k is 2

    Output:
        - number of subarrays whose element's sum is divisible by k
        - single value

    Edge Cases:
        - array size is 1
        - no subarray satisfying the condition
        - complete array itself is divisible by k

    Brute Force:
        - initialize num_of_subarray = 0
        - for ith element in nums:
            - initialize sum = 0
            - from j = i to n-1, accumulate sum
            - if at any index j, sum % k == 0, increment num_of_subarray
        - finally return num_of_subarray

    Complexity:
        Time: O(n^2)
        Space: O(1)

    Repeated Work:
        - We are repeatedly calculating sum for each element in nums

    Information to Remember:
        - suppose prefixSum[i] % k = r = prefixSum[j] % k, where i!=j, then 
        - it is definite that the sum of elements from i+1 to j is divisible by k
        - so if we somehow know that this remainder already been encountered and how many times, then we just need to increment the num_of_subarray by the frequency of remainder already encountered
        - also if current prefixSum is itself 0, then increment num_of_subarray by 1 or just store frequency of 0 as 1 by default and increment num_of_subarray by frequency of 0 encountered and increment frequency
        - if negative remainder is encountered, normalize it to equivalent positive remainder

    Pattern:
        - remainder -> frequency
        - hashmap + prefixSum