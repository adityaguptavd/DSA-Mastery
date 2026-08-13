Learning Journal:
    - Input:
        - an integer array nums of length n
        - multiple opertaions [startIndex, endIndex]
        - for every operation have to add 1 from startIndex to endIndex
    
    - Output:
        - maximum value after performing all operations
    
    Edge Cases:
        - startIndex == endIndex
        - endIndex == n-1
    
    Brute Force:
        - for each operation:
            - add 1 from startIndex to endIndex as:
                - ++nums[i]
        - scan nums array to find max value

    Complexity:
        - Time: O(n * q), where n is length of array nums and q is number of operations to perform
        - Auxiliary Space: O(1)
        - Total Space: O(n)
    
    Repeated Work:
        - for overlapping operations, we are performing multiple operations on same index

    Information to Remember:
        - we are iterating over the entire range while we can just mark where the effect starts and where it stops
        - we can mark startIndex as +1 and endIndex + 1 as -1, which means startIndex is the point from where effect starts and stops at endIndex + 1
        - after that we can find the updated value by cumulative sum

    Pattern:
        - range updates and cumulative sum -> prefix sum + difference array