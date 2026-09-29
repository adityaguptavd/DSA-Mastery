class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // orders
        size_t m = matrix.size();
        size_t n = matrix[0].size();
        // separate flag for first column
        bool firstColumnZero = false;
        // mark zeroes
        for(size_t row = 0; row < m; ++row) {
            for(size_t col = 0; col < n; ++col) {
                if(matrix[row][col] == 0) {
                    // mark row and col zeroes
                    matrix[row][0] = 0;
                    if(col == 0) {
                        firstColumnZero = true;
                    }
                    else {
                        matrix[0][col] = 0;
                    }
                }
            }
        }
        // set/apply zeroes non-first row and column
        for(size_t row = 1; row < m; ++row) {
            for(size_t col = 1; col < n; ++col) {
                if(matrix[row][0] == 0 || matrix[0][col] == 0) {
                    matrix[row][col] = 0;
                }
            }
        }
        // set zero to first row
        if(matrix[0][0] == 0) {
            for(size_t i = 0; i < n; ++i) {
                matrix[0][i] = 0;
            }
        }
        // set zero to first column
        if(firstColumnZero) {
            for(size_t i = 0; i < m; ++i) {
                matrix[i][0] = 0;
            }
        }
    }
};