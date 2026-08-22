Learning Journal:
    Input:
        - a 1-indexed array of integers numbers that is already sorted in non-decreasing order
        - a specific target number

    Output:
        - Return the indices of the two numbers index1 and index2 whose value's sum equals the target value, each incremented by one, as an integer array [index1, index2] of length 2.

    Edge Cases:
        - no solution is there (not possible in this case since question explicitly telling that exactly one solution exists)
        - array size is 2 (minimum size according to contraints)
        - duplicate values present
        - target is negative/zero

    Brute Force:
        - for each element in array, search for its complement (target - elem) in whole array and return index where complement is found and current index

    Complexity:
        Time: O(n^2)
        Auxiliary Space: O(1)

    Repeated Work:
        - We are searching for complements for each element which leads to repeated traversal of same array

    Information to Remeber:
        - If we know whether we have enountered the current element's complement in previous parts of the array
        - We have already solved this in hashmap pattern. But the problem explicitly mentioned here to use constant space. So this approach is also not worth to consider
        - Now since the problem mentioned the array is sorted. We can find target sum using two pointers approach
        - Keeping two pointers at the edges of the array and calculate sum
        - If sum > target:
            - move right pointer towards left 
        - if sum < target:
            - move left pointer towards right
        - if sum == target:
            - return [left pointer, right pointer]

    Pattern:
        Two pointers