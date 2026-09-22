Learning Journal:
    Input:
        - an array of non-overlapping intervals intervals
        - intervals is sorted in ascending order by starti
        - an interval newInterval = [start, end]
    
    Output:
        - Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).
        - Return intervals after the insertion.

    Brute Force:
        - copy the intervals array
        - while copying find the appropriate location for the new interval to be inserted
        - once any interval's start index become greater than new interval, that's the location of the new interval
        - store the new interval as current_merged_interval
        - starting from that location, merge the further intervals (if necessary) into the current_merged_interval. If not merging, then add current_merged_interval at founded location and copy further intervals (after the last merged interval)

    Complexity:
        Time: O(n)
        Space: O(n), for storing output
        