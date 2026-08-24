Optimized Algorithm:
    - sort the given array nums
    - initialize triplets = []
    - i = 0
    - while i <= n-3 and nums[i] <= 0:
        - required sum = -nums[i]
        - initialize two pointers L = i + 1 and R = n - 1:
        - apply two sum between L and R (inc.) to find required sum until L < R:
            - once found push {nums[i], nums[L], nums[R]} into triplets
            - while(++L < R and nums[L] == nums[L - 1]) {}
            - while(L < --R and nums[R] == nums[R + 1]) {}
        - while(++i <= n-3 and nums[i] == nums[i - 1]) {}
    - return triplets

Complexity:
    Time: O(n^2)
    Auxiliary Space: O(1)
    Total Space: O(m), where n is size of given array nums and m is size of triplets returned