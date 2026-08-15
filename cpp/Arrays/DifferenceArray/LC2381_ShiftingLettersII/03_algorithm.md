Optimized Algorithm:
    - create an integer diff array net_shift of size s.length + 1
    - for each shift in shifts:
        - shift_value = direction == 0 ? -1: +1
        - net_shift[start] += shift_value
        - net_shift[end + 1] -= shift_value
    - current_net_shift = 0
    - for i = 0 to s.length - 1
        - current_net_shift += diff[i]
        - s[i] += current_net_shift, while applying circular increment with remainder normalization
    - return s

Complexity:
    Time: O(shifts.length + s.length)
    Space: O(s.length)