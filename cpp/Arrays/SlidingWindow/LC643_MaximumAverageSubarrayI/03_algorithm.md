Optimized Algorithm:
    - initialize the window: left = 0, right = k - 1
    - find sum of the elements in current window and store in current_sum
    - initialize max_sum = current_sum
    - shift window: ++left, ++right
    - while right < n:
        - current_sum = current_sum - nums[left - 1] + nums[right]
        - max_sum = max(current_sum, max_sum)
        - ++left, ++right
    - return max_sum / k

Complexity:
    Time: O(n)
    Space: O(1)