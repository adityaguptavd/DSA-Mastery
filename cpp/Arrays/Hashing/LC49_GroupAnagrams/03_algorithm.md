Optimized Algorithm:
    - if n == 1, return [strs] // we can skip this step
    - create a group_array = []
    - create a hashmap(string, size_t)
    - iterate over strs
    - for each str in strs:
        - copy and sort str into copy_sorted_str
        - check if copy_sorted_str exists in hashmap
        - if exists:
            - then extract corresponding stored value as index
            - push str into array at that index in group_array
        - else:
            - store { copy_sorted_str -> group_array.size() }
            - push [str] into group_array
    - finally return group_array
    
Complexity:
    Time: O(n * klogk)
    Space: O(n)
    - where n is the size of array of strings and k is the maximum length of a string