Optimized Algorithm:
    - create a diff array of size 10^5 + 2 with all values initialized as 0
    - for each interval:
        - ++diff[start]
        - --diff[end + 1]
    - current = max-overlap = 0
    - for i=0 to 10^5
        - current += diff[i]
        - max-overlap = max(max-overlap, current)
    - return max-overlap