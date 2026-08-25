Optimized Algorithm:
    - initialize edges of the window: left = 0, right = left + k - 1
    - find current_sum of current window [left, right]
    - initialize max_sum = current_sum
    - ++left, ++right
    - while right < n:
        - current_sum = current_sum - arr[left-1] + arr[right]
        - max_sum = max(max_sum, current_sum)
        - ++left, ++right
    - return max_sum

Complexity:
    Time: O(n)
    Space: O(1)