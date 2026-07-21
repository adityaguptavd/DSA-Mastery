Learning Journal:
    Input:
        - array of integers nums and an integer target
        - values can be +ve, -ve or even 0
        - array can neither be empty nor single sized
        - not sorted
    Output:
        - array of two +ve (incl. 0) integers
        - single answer
        - no duplicate
    Constraints:
        - 2 <= nums.length <= 10^4  --> O(n) or O(nlogn)
        - -10^9 <= nums[i] <= 10^9
        - -10^9 <= target <= 10^9
        - Only one valid answer exists.

    Edge Cases:
        - array contains exactly two elements --> since exactly one answer exists, 0, 1 is the answer
    Hidden Clues:
        - two integers -> two pairs -> two pointers/hashing
    Brute Force:
        - iterate over the array
        - search compliment (target - current) of the current element in the array
        - return the indices of the compliment elements
        - Time Complexity - O(n^2)
        - Space Complexity - O(1)
    Repeated Work:
        - We are iterating the same array for each element to search compliment.
    Information to Remember:
        - If we somehow know whether we have seen the compliment of the current element in past iterations, then we can easily avoid searching over and over.
        - But since we have to return indices instead of elements, we will also need the indices of the seen compliments.
    Pattern:
        - already seen? -> hashmap/hashset
        - already seen element mapping with their indices -> hashmap