Optimized Algorithm:
    - initialize left = 0
    - initialize zero_count = 0
    - for right = 0 to n - 1:
        - if nums[right] == 0:
            - ++zero_count
        - if zero_count > k:
            - if nums[left] == 0:
                - --zero_count
            - ++left
    - return right - left

Complexity:
    Time: O(n)
    Space: O(1)