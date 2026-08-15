Learning Journal:
    Input:
        - a 2D integer array ranges and two integers left and right
        - Each ranges[i] = [start, end] represents an inclusive interval between start and end.
        - An integer x is covered by an interval ranges[i] = [starti, endi] if starti <= x <= endi.

    Output:
        - Return true if each integer in the inclusive range [left, right] is covered by at least one interval in ranges. Return false otherwise.

    Brute Force:
        - for each integer x from left to right (inclusive both):
            - covered = false
            - for each [start, end] in ranges:
                - if start <= x <= end:
                    - covered = true
            - if not covered:
                return false
        - return true

    Complexity:
        Time: O(n * m)
        Space: O(1)
        - where n = size of ranges and m = left to right range size

    Repeated Work:
        - for each range, we are repeateadly checking coverage for same left to right range again and again
    
    Information to Remember:
        - We can mark where the range starts and where the range ends (end + 1) on an array's index
        - While computing cumulative sum, check whether sum == 0 or not.
        - sum == 0 indicates inactive range while sum > 0 indiactes active range
        - so, if current index (while computing sum) exists in range left <= index <= right and sum == 0, immediately return false
        - at last return true