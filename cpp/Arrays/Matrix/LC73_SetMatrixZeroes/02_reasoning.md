Learning Journal:
    Input:
        - an m x n integer matrix

    Output:
        - if an element is 0, set its entire row and column to 0's.
        - You must do it in place.

    Edge Cases:
        - all elements are zero
        - no element is zero
        - corresponding column or row is already zero
    
    Brute Force:
        - for row = 0 to m - 1:
            - for col = 0 to n - 1:
                - if matrix[row][col] == 0:
                    - for i = 0 to m - 1:
                        - matrix[i][col] = 0
                    - for i = 0 to n - 1:
                        - matrix[row][i] = 0

    Complexity:
        Time: O(m x n x (m + n))
        Space: O(1)