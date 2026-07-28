Learning Journal:
    Input:
        - integers array nums and an integer k
        - negative and non-negative integers both
        - k is non-negative
        - array will contain at least one element (according to constraints)

    Output:
        - boolean
        - single value

    Edge Cases:
        - array size is 1
        - array is sorted
        - array contains all same elements
        - k = 0
        
    Brute Force:
        - if size of array is 1 or k = 0, return false
        - for each element in nums:
            - search for its duplicate in whole array except current position
            - if found then check |i-j| <= k or not:
                if yes, then return true
                else continue
        - after loop exits return false

    Complexity:
        Time: O(n^2)
        Space: O(1)

    Constraints:
        - 1 <= nums.length <= 10^5
        - -10^9 <= nums[i] <= 10^9
        - 0 <= k <= 10^5
        - So, we have to optimize our algorithm within O(nlogn) or O(n)
    
    Repeated Work:
        - We are traversing same elements again and again just to check duplicate and index

    Information to Remember:
        - We can store already seen elements with their index, so that we don't have to search for duplicate elements and their indices again and again
        - We can store element -> index mapping
        - Now if we already have any mapping for that element, we compare differences of indices and k and if condition is satisfied, return true immediately
        - Otherwise, update the element's index mapping with current index, since we have to find nearby elements, so we'll need only recent element's index
        - After loop ends, we'll just return false
    
    Complexity:
        Time: O(n)
        Space: O(m), where m is number of distinct elements in nums, m <= n.

    Pattern:
        - Already seen and at which position -> HashMap