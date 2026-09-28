class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // matrix order
        size_t matrix_order = matrix.size();
        // layer by layer rotation
        for(size_t layer = 0; layer < matrix_order / 2; ++layer) {
            for(size_t col = layer; col <= matrix_order - layer - 2; ++col) {
                // one 4 cell rotation cycle
                int temp = matrix[layer][col];
                matrix[layer][col] = matrix[matrix_order - col - 1][layer];
                matrix[matrix_order - col - 1][layer] = matrix[matrix_order - layer - 1][matrix_order - col - 1];
                matrix[matrix_order - layer - 1][matrix_order - col - 1] = matrix[col][matrix_order - layer - 1];
                matrix[col][matrix_order - layer - 1] = temp;
            }
        }
    }
};