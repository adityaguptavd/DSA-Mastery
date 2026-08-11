**Problem Description:**
You are given an array of zeroes and several range updates. Each update adds a value to every element in a range.
You need to determine whether any element becomes greater than a given limit.

Problem
Given: n, updates, limit
where each update is:
    [startIndex, endIndex, value]
Initially:
    arr = [0, 0, 0, ..., 0]
Apply all updates.
Return:
    true, if every element remains <= limit.
Otherwise return:
    false

Example 1
    n = 6
    updates = [
        [1, 4, 3],
        [2, 5, 2]
    ]
    limit = 5

    Final values:
        [0, 3, 5, 5, 5, 2]
    Every value is <= 5.
    Result:
        true

Example 2
    n = 6
    updates = [
        [1, 4, 4],
        [2, 5, 3]
    ]
    limit = 5

    Final values:
        [0, 4, 7, 7, 7, 3]
        Some elements exceed 5.
    Result:
        false

Constraints
    1 <= n <= 10^5
    0 <= updates.length <= 10^5
    0 <= startIndex <= endIndex < n
    -10^4 <= value <= 10^4
    -10^9 <= limit <= 10^9