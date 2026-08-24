Learning Journal:
    Input:
        - an integer array nums
        - poitive/zero/negative integers

    Output:
        - return all the distinct triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

    Edge Cases:
        - all numbers are positive
        - all numbers are negative
        - all numbers are zero
        - no triplet exist
        - duplicate triplet exists
        - array size is 3

    Brute Force:
        - triplets = []
        - from i = 0 to n - 1:
            - from j = i + 1 to n - 1:
                - from k = j + 1 to n - 1:
                    - if nums[i] + nums[j] + nums[k] == 0:
                        - make additional check/scan whether this triplet exists in triplets array (we can optimize this later)
                        - if not exists then:
                            - triplets.add([i, j, k])

        - return triplets

    Complexity:
        Time: O(n^3)
        Auxiliary Space: O(1)
        Total Space: O(m), where m = number of returned triplets
