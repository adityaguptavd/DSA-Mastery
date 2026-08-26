Optimized Algorithm:
    - n = s.length
    - if n == 0, return 0
    - create hashmap
    - initialize left = 0
    - initialize max_size = 0
    - for right = 0 to n - 1:
        - if s[right] exists in hashmap AND hashmap[s[right]] >= left:
            - left = hashmap[s[right]] + 1
        - hashmap[s[right]] = right
        - max_size = max(max_size, right - left + 1)
    - return max_size

Complexity:
    Time: O(n)
    Space: O(n)