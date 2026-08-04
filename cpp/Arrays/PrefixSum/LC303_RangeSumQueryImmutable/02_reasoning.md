Learning Journal:
    Input:
        - an integer array nums
        - left, right range
        - nums array is provided only once

    Output:
        - sum of the values within given range inclusive of both left and right values

    Edge Cases:
        - arary is of size 1
        - left and right both are same
        - left is greater than right (not possible based on constraints)

    Brute Force:
        - create a private member variable of type vector
        constructor():
            - store nums
        sumRange():
            - find sum of all the elements from left to right
            - return sum
    
    Complexity:
        constructor():
            Time: O(1)
            Space: O(1)
        sumRange():
            Time: O(n)
            Space: O(1)

    Constraints:
        1 <= nums.length <= 10^4
        -10^5 <= nums[i] <= 10^5
        0 <= left <= right < nums.length
        At most 10^4 calls will be made to sumRange.
        - O(n) complexity is acceptable

    Repeated Work:
        - We are calculating sum again and again on each query

    Information to Remember:
        - We can store sum upto i on ith index in a new array and store it as member variable
        - Now we can just use those sums to calculate and return the answer directly.

    Pattern:
        - sum range -> prefix sum