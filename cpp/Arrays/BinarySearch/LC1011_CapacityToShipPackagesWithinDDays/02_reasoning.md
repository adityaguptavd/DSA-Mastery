Learning Journal:
    Input:
        - weights array
        - days within which all packages have to be shift

    Output:
        - least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.

    Edge Cases:
        - weights.length == days
    
    Brute Force:
        - for i = max(weights) to sum(weights):
            - capacity = i
            - day = 1
            - for j = 0 to weights.length - 1:
                - if capacity >= weights[j]:
                    - capacity -= weights[j]
                - else:
                    - ++day
                    - capacity = i - weights[j]
            - if day <= days:
                - return i
    
    Complexity:
        Time: O((S - M) * n)
        Space: O(1)
        - where S = sum of weights
                M = max among weights
                n = weights.length

    Information to exploit:
        - If any capacity C is feasible, then larger capacities will also be feasible
    
    Pattern:
        - monotonic search -> binary search