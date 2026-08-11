**Problem Description:**
You are given an integer array nums of length n, initially containing arbitrary values.
You are also given several range updates:
    [startIndex, endIndex, value]
For each update, add value to every element from startIndex through endIndex, inclusive.
Return the final array after applying all updates.
Example:
    nums = [10, 20, 30, 40, 50]
    updates = [
        [1, 3, 5],
        [2, 4, -10]
    ]
After the first update:
    [10, 25, 35, 45, 50]

After the second:
    [10, 25, 25, 35, 40]
So return:
    [10, 25, 25, 35, 40]

Constraints:
    1 <= n <= 10^5
    0 <= updates.length <= 10^5
    0 <= startIndex <= endIndex < n
    -10^4 <= value <= 10^4