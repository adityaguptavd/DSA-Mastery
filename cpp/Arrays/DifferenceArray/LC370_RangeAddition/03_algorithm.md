Optimized Algorithm:
    - create a diff array of size n + 1 all initialized with 0
    - for each update [startIndex, endIndex, inc]:
        - diff[startIndex] += inc
        - diff[endIndex + 1] -= inc
    - initialize result array of size n with all values 0
    - currentRunningSum = 0
    - reconstruct result array by applying cumulative prefix sum in diff:
        - currentRunningSum += diff[i]
        - result[i] = currentRunningSum
    - return final result array

Complexity:
    Time: O(n + q)
    Space: O(n + 1 + n) -> O(n)