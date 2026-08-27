Optimized Algorithm:
    - initialize left = 0, right = 0
    - current_sum = nums[right]
    - min_size = nums[right] >= target ? 1: +infinity
    - ++right
    - while right <= n - 1:
        - current_sum += nums[right]
        - while current_sum >= target:
            - min_size = min(min_size, right - left + 1)
            - current_sum -= nums[left]
            - ++left
        - ++right
    - return min_size == +infinity ? 0: min_size

Complexity:
    Time: O(n)
    Space: O(1)