Learning Journal:
    Input:
        - an array of integers arr
        - any signed/unsigned integers including 0

    Output:
        - boolean value
        - single value

    Edge Cases:
        - array is of exactly one size
        - all elements are distinct
        - all elements are same

    Brute Force:
        - create a hashmap to store element -> frequency
        - iterate over each element in array: -> O(n)
            - increment frequency of each element encountered
        - for each distinct element stored in hashmap: -> O(k)
            - get its frequency
            - compare with other stored element's frequency -> O(k)
            - if any matches, return false
            - else continue
        finally return true

    Complexity:
        Time: - O(n + k*k), where k = distinct element in arr
                - in worst case, n = k, then O(n + n*n) -> O(n^2)
        Space: O(k)

    Constraints:
        1 <= arr.length <= 1000
        -1000 <= arr[i] <= 1000

    Repeated Work:
        - Repeatedly comparing each element again and again

    Information to Remember:
        - We just need to know whether this frequency has already been seen or not

    Pattern:
        - already seen -> hashset
        - so this problem is hashmap + hashset