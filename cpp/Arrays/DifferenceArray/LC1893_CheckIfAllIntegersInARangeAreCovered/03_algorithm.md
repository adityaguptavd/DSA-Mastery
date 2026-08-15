Optimized Solution:
    - create a diff array of size 52
    - for each start, end in range:
        - ++diff[start]
        - --diff[end + 1]
    - current = 0
    - for i = 0 to 50:
        - current += diff[i]
        - if current == 0 && left <= i <= right:
            - return false
        - return true

Complexity:
    Time: O(n)
    Space: O(m)
    - where n is number of ranges given and m is maximum possible value of integers in ranges