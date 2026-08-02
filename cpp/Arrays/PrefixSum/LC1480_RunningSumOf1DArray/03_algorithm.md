Optimized Algorithm:
- create an output array
- for ith element in nums:
    - if i == 0:
        output[i] = nums[i]
    - else output[i] = output[i - 1] + nums[i]

Complexity: 
    Time: O(n)
    Auxiliary Space: O(1)
    Total Space: O(n)