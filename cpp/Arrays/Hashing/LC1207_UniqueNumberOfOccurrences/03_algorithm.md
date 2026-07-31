Optimized Algorithm:
    - if size of arr is 1, return true
    - create a hashmap and hashset
    - build elem -> freq map using arr and store in hashmap
    - iterate over each distinct element stored in hashmap:
        - if its frequency is already seen and stored in hashset:
            return false:
        - else store in hashset
    - finally return true

Complexity:
    Time: - O(n + k)
    Space: O(k)