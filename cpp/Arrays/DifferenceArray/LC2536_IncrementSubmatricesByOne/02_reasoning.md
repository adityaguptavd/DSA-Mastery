Learning Journal:
    Input:
        - a positive integer n, indicating that we initially have an n x n 0-indexed integer matrix mat filled with zeroes.
        - a 2D integer array query
        - query[i] = [row1i, col1i, row2i, col2i]

    Output:
        - Return the matrix mat after performing every query

    Edge Cases:
        - n == 1
        - row == n - 1 || col == n - 1
    
    Brute Force:
        - create an n x n matrix with all values initialized to 0
        - for each query:
            - for i=row1 to row2:
                - for j=col1 to col2:
                    - matrix[i][j] += 1
        - return matrix

    Complexity:
        Time: O(n^2 * q)
        Auxiliary Space: O(1)
        Total Space: O(n^2)

    Repeated Work:
        - As always we are updating same indices again and again

    Information to Remember:
        - We can mark the locations where effect starts and where effect ends but this time in 2D way

    Pattern:
        - range updates with cumulative sum -> difference array + prefix sum