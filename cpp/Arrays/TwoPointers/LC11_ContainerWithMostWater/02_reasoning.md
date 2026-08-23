Learning Journal:
    Input:
        - an integer array height of length n
        - There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

    Output:
        - Find two lines that together with the x-axis form a container, such that the container contains the most water.

        - Return the maximum amount of water a container can store.

    Edge Cases:
        - duplicate vertical lines
        - two same max sized containers with different height and base
        - size is 2
        - max container with base of size n
        - either of the base and height is equal to 1
        - any vertical line has height 0

    Brute Force:
        - initialize max_volume = 0
        - for each height:
            - compute volume with all the other heights onwards
            - if max_volume < computed volume:
                - update max_volume with computed volume
        - return max_volume

    Complexity:
        Time: O(n^2)
        Auxiliary Space: O(1)