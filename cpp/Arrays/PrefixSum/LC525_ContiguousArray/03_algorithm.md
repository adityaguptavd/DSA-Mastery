Optimized Algorithm:
    - initialize a least_recent_prefix hashmap with value pair(0, -1)
    - initialize running prefix sum = 0
    - initialize largest subarray length = 0
    - for ith element in nums:
        - if nums[i] is 0, decrement running prefix sum
        - else if nums[i] is 1, increment running prefix sum
        - if running prefix sum exists in hashmap:
            - update largest subarray length = max(largest subarray length, i - hashmap.get(running prefix sum))
        - else store running prefix sum -> i in hashmap

    - finally return largest subarray length

Complexity:
    Time: O(n)
    Space: O(n)