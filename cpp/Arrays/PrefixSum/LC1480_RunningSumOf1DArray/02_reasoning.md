Learning Journal:
    Input:
        - an array nums
        - integer values
        - non-empty array

    Output:
        - array of running sum

    Edge Cases:
        - contains exactly one value

    Brute Force:
        - create an output array
        - for ith value:
            - calculate sum from 0 to i in nums and store at output[i]
        - finally return output

    Complexity:
        Time: O(n^2)
        Space: O(1), since output array is meant to return

    Constraints:
        - 1 <= nums.length <= 1000
        - -10^6 <= nums[i] <= 10^6
        - O(n^2) is not acceptable

    Repeated Work:
        - For ith index we are calculating sum from 0 to i in nums

    Information to Remember:
        - We already have sum from 0 to i-1 in output array
        - We can reuse that value

    Pattern:
        - sum so far -> prefix sum