Optimized Algorithm:
    - create two pointers: L and R
    - L = 0
    - R = s.length - 1
    - while L < R:
        - if s[L] is not valid:
            - increment L
        - if s[R] is not valid:
            - increment R
        - if s[L] and s[R] both are valid:
            - convert both to lowercase
            - compare s[L] and s[R]
            - if not equal -> return false
            - else increment L and R

    - return true

Complexity:
    Time: O(n)
    Space: O(1)