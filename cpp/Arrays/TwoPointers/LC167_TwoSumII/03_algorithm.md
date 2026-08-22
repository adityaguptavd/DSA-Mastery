Optimized Algorithm:
    - initialize L = 0, R = n - 1
    - while L < R:
        - if sum > target:
            - dec R
        - else if sum < target:
            - inc L
        - else
            return [L + 1, R + 1]

Complexity:
    Time: O(n)
    Auxiliary Space: O(1)