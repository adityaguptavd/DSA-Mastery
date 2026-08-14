You are given n intervals:
[start, end]
Each interval represents a range that is active from start through end, inclusive.
Return the maximum number of intervals overlapping at any point.
Example
intervals = [
    [1, 5],
    [2, 6],
    [4, 8],
    [7, 9]
]
At position 4:
[1,5]
[2,6]
[4,8]
are active simultaneously.
So the maximum overlap is:
3
Constraints
1 <= intervals.length <= 10^5
0 <= start <= end <= 10^5