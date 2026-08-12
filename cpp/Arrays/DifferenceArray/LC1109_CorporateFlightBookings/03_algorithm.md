Optimized Alogrithm:
    - create a diff array of size n + 1
    - create a result array of size n
    - for each bookings:
        - diff[first - 1] += passengers
        - diff[last] -= passengers
    - current = 0
    - iterate and find cumulative sum and update:
        - current += diff[i]
        - result[i] = current
    - finally return result

Complexity:
    Time: O(n + bookings.length)
    Space: O(n)