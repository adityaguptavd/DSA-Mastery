Optimized Algorithm:
- If k = 0 or array size is 1, return false
- create hashmap mp
- for each element in nums:
    - check if the element already exists in the hashmap:
        - if exists, check difference of current index and stored index of the current element
            - if condition satisfies, return true
            - else update the stored index with current index
        - else if doesn't exists, store current element -> current index in mp
- finally return false

Complexity:
    Time: O(n)
    Space: O(m), where m is the number of distinct elements in nums, i.e., m <= n