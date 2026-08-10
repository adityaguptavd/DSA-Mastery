Learning Journal:
    Input:
        - an array of length 'length' (say n) with initialized value of 0
        - several updates in format [startIndex, endIndex, inc]
        - startIndex and endIndex is inclusive

    Ouptut:
        - updated array with all updates applied

    Edge Cases:
        - startIndex and endIndex is same
        - inc value is negative
        - overlapping updates from multiple updates
        - endIndex == n-1

    Brute Force:
        - for each [startIndex, endIndex, inc] in updates:
            - iterate in array from startIndex to endIndex and update each value
        - finally return updated array

    Complexity:
        Time: O(n * q), where n is length of array and q is number of updates
        Space: O(1)

    Repeated Work:
        - for multiple queries, if updates are overlapping then we are applying updates to same index again and again
    
    Information to Remember:
        - what if we acuumulate all the updates for an index separately and build the resulting array later by applying those accumulated updates at once?
        - But for ranges in millions, we still have to visit those millions of indices
        - So, instead of accumulating the final update for every index, can we accumulate information about where an update starts and where it stops?
        - Later, we can use cumulative information to reconstruct the effect at every index

    Pattern:
        - Range updates -> Difference Array