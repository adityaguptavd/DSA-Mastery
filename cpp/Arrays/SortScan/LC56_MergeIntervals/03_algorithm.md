Optimized Algorithm:
    - sort the intervals array
    - create a merged_intervals array
    - current_merged_interval = intervals[0]
    - for i = 1 to intervals.length - 1:
        - if intervals[i][0] <= current_merged_interval[1]
            - current_merged_interval = [current_merged_interval[0], max(intervals[i][1], current_merged_interval[1])]
        else:
            - merged_intervals.push(current_merged_interval)
            - current_merged_interval = intervals[i]

    - merged_intervals.push(current_merged_interval)
    - return merged_intervals

Complexity:
    Time: O(nlogn + n) -> O(nlogn)
    Space: O(n)