Optimized Algorithm:
    - Create an empty hashmap. O(1)
    - Traverse the array O(n)
    - For every element:
        - Compute its complement O(1)
        - Check if complement exists in hashmap O(1)
        - if exists:
            - return the stored index of complement and current index O(1)
        - else:
            - store the current value along with its index (value -> index map) O(1)
        - Continue until loop ends or answer is found

Complexity:
    Time: O(n)
    Space: O(n)