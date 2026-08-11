Learning Journal:
    Input:
        - an integer array nums of size n
        - range updates: [startIndex, endIndex, value]
    
    Output:
        - modified array after applying updates on nums

    Edge Cases:
        - no updates are given
        - startIndex == endIndex
        - endIndex == n - 1
        - value is negative or 0

    Brute Force:
        - for each update:
            - update each element from startIndex to endIndex in nums
        - return updated array

    Complexity:
        Time: O(n * q)
        Space: O(1)

    Repeated Work:
        - if two updates are overlapping on same index, we are updating that index again and again
        
    Information to Remember:
        - if we store overall updates for each index, then we can avoid updating same index again and again
        - but still we'll iterate all the indices from start to end
        - we can mark the updates like updation of value starts at startIndex and ends at endIndex + 1

    Pattern:
        - range updates -> difference array + prefix sum