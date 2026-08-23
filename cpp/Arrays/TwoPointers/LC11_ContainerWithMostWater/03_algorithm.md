Optimized Algorithm:
    - initialize two pointers L = 0 and R = n - 1
    - max_area = 0
    - while L < R:
        - compute area between L and R
        - update max_area:
            - max_area = max(max_area, computed area)
        - move the limiting height inwards

Complexity:
    Time: O(n)
    Auxiliary Space: O(1)