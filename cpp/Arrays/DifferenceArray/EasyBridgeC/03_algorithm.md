Optimized Algorithm:
    - given nums array of size n
    - create a diff array of size n + 1, all initialized to 0
    - for each operation:
        - ++diff[startIndex]
        - --diff[endIndex + 1]

    - current = 0;
    - max_value = -INFINITY
    - for each elem in diff:
        - current += elem
        - max_value = max(max_value, current + nums[i])
    - return max

Complexity:
    Time: O(n + q)
    Space: O(n)