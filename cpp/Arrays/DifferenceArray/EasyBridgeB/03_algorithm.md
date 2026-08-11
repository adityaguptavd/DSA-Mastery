Optimized Algorithm:
    - create a diff array of size n + 1
    - for each update:
        - diff[startIndex] += value
        - diff[endIndex + 1] -= value
    - intialize currentSum = 0
    - for each element in arr:
        - currentSum += diff[i]
        - if currentSum > limit, return false
    - return true

Complexity:
    Time: O(n + q)
    Space: O(n)