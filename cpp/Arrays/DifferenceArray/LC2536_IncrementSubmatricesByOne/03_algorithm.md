Optimized Algorithm:
    - create a diff matrix of size (n + 2) x (n + 2) initialized with 0 (padding 1 x 1 from all sides)
    - for each query:
        - ++diff[row1][col1]
        - --diff[row1][col2 + 1]
        - --diff[row2 + 1][col1]
        - ++diff[row2 + 1][col2 + 1]

    - reconstuct the matrix array using prefix sum in 2D matrix

    - return matrix

Complexity:
    Time: O(n^2  + q)
    Space: O(n^2)