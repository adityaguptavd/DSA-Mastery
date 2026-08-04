Optimized Algorithm:
    - maintain a running prefix sum
    - maintain a counter for number of subarrays whose element's sum is equal to target k
    - for ith element in nums:
        - update prefix sum by adding ith elem in it
        - if prefix sum is equal to target k itself, increment counter
        - find (prefix sum - target k) in hashmap:
            - if exists:
                - increment counter by the corresponding frequency
                - increment frequency for prefix sum in hashmap by 1
            - else:
                - store frequency 1 against current prefix sum in hashmap

    - finally return counter

Complexity: 
    Time: O(n)
    Space: O(n)