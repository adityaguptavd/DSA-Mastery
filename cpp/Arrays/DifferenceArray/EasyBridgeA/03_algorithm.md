Optimized Algorithm:
    - create a diff array of size n + 1 intialized with all values as 0
    - for each update:
        - diff[startIndex] += value
        - diff[endIndex + 1] -= value
    - initialize current = 0
    - for each element in nums:
        - current += diff[i]
        - nums[i] += current
    - return nums

Complexity:
    Time: O(n + q)
    Space: O(n)