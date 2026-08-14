Learning Journal:
    Input:
        - given n intervals [start, end]
        - each interval is range which is active from start to end, inclusive

    Output:
        - maximum number of intervals overlapping at any point

    Edge Cases:
        - start == end
        - end == maximum possible value

    Brute Force:
        - create an array of size 10^5
        - for each interval, add +1 from array[start] to array[end]
        - finally scan the array and calculate maximum
        - return maximum

    Complexity:
        Time: O(n * m), where n is size of intervals and m is maximum possible value of start/end
        Space: O(m)

    Repeated Work:
        - Adding +1 again and again at same overallping index

    Information to Remember:
        - Mark the start and end boundaries with +1 and -1 and find cumulative sum
        - the one with highest cumulative sum will be the answer

    Pattern:
        - range active + cumulative sum -> difference array + prefix sum