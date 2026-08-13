**Problem Description:**

You are given an integer array nums of length n.
You are also given multiple operations:
    [startIndex, endIndex]
For every operation, add 1 to every element from startIndex through endIndex, inclusive.
Return the maximum value present in the final array.
Example
    nums = [2, 1, 3, 0, 1]

    operations = [
        [0, 2],
        [1, 4],
        [2, 3]
    ]
    After [0, 2]:
        [3, 2, 4, 0, 1]
    After [1, 4]:
        [3, 3, 5, 1, 2]
    After [2, 3]:
        [3, 3, 6, 2, 2]
    Maximum: 6
    Return: 6
Constraints
    1 <= n <= 10^5
    0 <= operations.length <= 10^5
    0 <= startIndex <= endIndex < n
    -10^4 <= nums[i] <= 10^4