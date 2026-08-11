Optimized Algorithm:
    - create a diff array of size k = 1001
    - for each trip in trips:
        - diff[from] += passengers
        - diff[to] -= passengers
    - current = 0
    - for each elem in diff:
        current += elem
        if(current > capacity) return false
    - return true

Complexity:
    Time: O(trips.length + k)
    Space: O(k)
    - where k is constant in this problem