**Problem Description:**
You have an array of length 'length', initially filled with zeroes:
    [0, 0, 0, ..., 0]
You are given several updates. Each update is:
[startIndex, endIndex, inc]
meaning:
    Add inc to every element from startIndex through endIndex, inclusive
After applying all updates, return the resulting array

Example:
    length = 5
    updates = [
        [1, 3, 2],
        [2, 4, 3],
        [0, 2, -2]
    ]