Learning Journal:
    Input:
        - an array of intervals
        - intervals[i] = [starti, endi]
    
    Output:
        - return an array of the non-overlapping intervals that cover all the intervals in the input.

    Brute Force:
        - pick one interval [x1, y1]
        - find another interval [x2, y2] in the array that satisfies either one of the condition:
            - either x1 or y1 lies in [x2, y2]
            - or x2 or y2 lies in [x1, y1]
        - if found:
            - merged interval = [min(x1, x2), max(y1, y2)]
        - loop till the end of the intervals

    Complexity:
        Time: O(n^2)
        Space: O(n), for storing output
        