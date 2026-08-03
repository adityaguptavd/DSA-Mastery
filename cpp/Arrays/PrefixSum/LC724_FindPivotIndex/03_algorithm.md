Optimized Algorithm 1:
- create a prefix sum array
- build prefix sum from nums array
- for ith element in nums:
    - calculate sum in range 0 to i-1 (left sum) and i+1 to n-1 (right sum) from prefix sum array as follows:
        - left sum:
            - if i = 0, then left sum = 0
            - else left sum = prefix sum at i-1
        - right sum:
            - if i = n-1, then right sum = 0
            - else right sum = (prefix sum at n - 1) - (prefix sum at i)
        
    - if left sum == right sum return i
- finally return -1

Complexity:
    Time: O(n)
    Auxiliary Space: O(n)
    Total Space: O(n)

Optimized Algorithm 2:
- inititalize two variables: prev_prefix_sum and total_sum with value 0
- calculate sum of the elements in array and store in total_sum
- for ith element in nums:
    - if prev_prefix_sum == (total_sum - nums[i] - prev_prefix_sum)
        - return i
    - else
        - prev_prefix_sum += nums[i]
- finally return -1

Complexity:
    Time: O(n)
    Space Complexity: O(1)