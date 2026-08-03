Learning Journal:
    Input:
        - an integer array nums
        - integer values
        - non-empty array

    Output:
        - pivot index
        - -1 or non-negative integers
        - multiple answers possible but has to return one

    Edge Cases:
        - calculating pivot for leftmost or rightmost element
        - array is of exactly size 1
        - no pivot index exists
        - more than one pivot index exist

    Brute Force:
        - iterate over each element in nums
        - for each elem:
            - calculate sum of all the elements in its left
            - calculate sum of all the elements in its right
            - if both sum are equal return current index
        - finally return -1

    Complexity:
        Time: O(n^2)
        Space: O(1)

    Constraints:
        1 <= nums.length <= 10^4
        -1000 <= nums[i] <= 1000

    Repeated Work:
        - For ith index we are calculating sum from 0 to i - 1 and i + 1 to n-1 in nums

    Information to Remember:
        - If we somehow already know the sum from 0 to i-1 and i+1 to n-1, then we can reuse that for all elements in the array nums

    Pattern:
        - sum in range -> prefix sum