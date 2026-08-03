Optimized Algorithm:
- create a prefix sum array
- build prefix sum from nums array
- for ith element in nums:
    - calculate sum in range 0 to i-1 (left sum) and i+1 to n-1 (right sum) from prefix sum array as follows:
        - left sum:
            - if i = 0, then left sum = 0
            - else left sum = 