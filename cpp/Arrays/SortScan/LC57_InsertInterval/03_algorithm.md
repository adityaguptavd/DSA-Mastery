Optimized Algorithm:
    - create an output array new_merged_intervals
    - for interval in intervals:
        - if new_interval.end < interval.start:
            - new_merged_intervals.push_back(new_interval)
            - new_merged_intervals.push_back(interval)
            - copy remaining intervals
            - finish
        - else if new_interval.start > interval.end:
            - new_merged_intervals.push_back(interval)
        - else:
            - merge until interval overlaps new interval
    - push new interval

Complexity:
    Time: O(n)
    Space: O(n)