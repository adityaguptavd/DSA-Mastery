Optimized Algorithm:
    - if size is 1, return true -> O(1)
    - create two hashmaps(s_mp, t_mp) -> O(1)
    - iterate s and t simultaneously -> O(n)
    - for ith character:
        - check s[i] exists in s_mp and t[i] exists in t_mp: -> O(1)
            - if exactly one exists, return false
            - else if none exists, then store s[i] -> t[i] mapping in s_mp and vice verse in t_mp
            - else if both exists and in either of them s[i] -> t[i] or t[i] -> s[i] respectively doesn't match return false
        - continue loop till string ends
    finally return true

    Complexity:
        - Time: O(n)
        - Space: O(n)
    Note: We can also use fixed sized array since charcters are fixed valid ascii.