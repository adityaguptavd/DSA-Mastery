Optimized Algorithm:
    - create two tracker pointers: reader/writer
    - while reader < n and writer < n:
        - move writer right to find position where the first non-zero element will go
        - find first non-zero element by moving reader right
        - swap both
        - increment reader and writer

Complexity:
    Time: O(n)
    Auxiliary Space: O(1)