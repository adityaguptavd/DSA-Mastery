Learning Journal:
    Input:
        - an array of integers nums and an integer k
        - negative and non-negative integers
    
    Output:
        - total number of subarray that sums to k
        - single value
        - non-negative integer value

    Edge Cases:
        - no subarray exists that sums to k
        - only one element present in array

    Brute Force:
        - initialize num_of_subarrays = 0
        - for ith element in nums:
            - calculate cumulative sum onwards
            - if sum is equal to k, increment num_of_subarrays
            - continue loop till the end of nums is not reached
        - finally return num_of_subarrays

    Complexity:
        Time: O(n^2)
        Space: O(1)

    Repeated Work:
        - We are repeatedily calculating sum of elements for each elem.

    Information to remember:
        - for ith element, if we know:
            - what is the sum of the elements upto i, and
            - whether we have encountered sum equal to (sum upto i - k) and how many times
        - This will tell us the exact range and number of the subarrays that sum upto k

    Pattern:
        - cumulative sum upto i -> prefix sum
        - to know the existence and frequency of required sum -> hashmap