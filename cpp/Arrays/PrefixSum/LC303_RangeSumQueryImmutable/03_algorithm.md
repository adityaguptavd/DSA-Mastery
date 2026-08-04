Optimized Algorithm:
    constructor:
        - create vector array as member variable and store prefix sum
        - for each ith element:
            - if i == 0, prefix_sum[i] = nums[i]
            - else prefix_sum[i] = prefix_sum[i - 1] + nums[i]
    sumRange method:
        - if left = 0, return prefix_sum[right]
        - else return prefix_sum[right] - prefix_sum[left - 1]

Complexity:
    constructor():
        Time: O(n)
        Space: O(n)
    sumRange():
        Time: O(1)
        Space: O(1)