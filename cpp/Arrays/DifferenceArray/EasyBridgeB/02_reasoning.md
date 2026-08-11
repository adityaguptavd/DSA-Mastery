Learning Journal:
    Input:
        - array of size n with all zeroes
        - updates [startIndex, endIndex, value]
        - limit

    Output:
        - boolean true or false
        - single value
    
    Edge Cases:
        - startIndex == endIndex
        - endIndex == n - 1
        - updates length is zero
        - updates value is either negative or zero
        - update value itself is greater limit

    Brute Force:
        - create array of size n with all values initialized with 0
        - for each update:
            - update the array from startIndex to endIndex
        - iterate over complete array again and check if any value exceeds limit
        - return true, if exceeds else false

    Complexity:
        Time: O(n * q + n)
        Auxiliary Space: O(1)
        Total Space: O(n)

    Repeated Work:
        - For overlapping updates we are updating same index multiple times
        - We are iterating same array twice, once while updating and second while checking limit exceed

    Information to Remember:
        Optimization Phase 1:
            - Instead of applying updates in multiple iterations, we can accumulate and find the effective update values and store them at correspoding index in another array
            - Then we can update the indices with corresponding effective update value in another array
            - While updating we can check whether the number is exceeding limit or not and based on that we can return boolean value

        Optimization Phase 2:
            - Above approach is still iterating all indices between the affected ranges
            - We can mark starting index in other array with positive update value representing starting of the update and negative update value at ending index + 1 representing the cancellation of update
            - Later, we can apply cumulative sum and update in array
            - while applying cumulative sum, if running sum exceeds limit, return false
            - else true

    Pattern:
        - range update by cumulative sum -> difference array + prefix sum