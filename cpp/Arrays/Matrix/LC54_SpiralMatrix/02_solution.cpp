class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // rows and cols
        int num_rows = static_cast<int>(matrix.size());
        int num_cols = static_cast<int>(matrix[0].size());
        // declare boundaries
        int top = 0,
            right = num_cols - 1,
            bottom = num_rows - 1,
            left = 0;

        vector<int> spiral_order;
        spiral_order.reserve(num_rows * num_cols);
        
        while(left <= right && top <= bottom) {
            // traverse top
            for(int i = left; i <= right; ++i) {
                spiral_order.push_back(matrix[top][i]);
            }
            // if row isn't finished yet
            if(top < bottom) {
                // traverse right
                for(int i = top + 1; i <= bottom; ++i) {
                    spiral_order.push_back(matrix[i][right]);
                }
                // traverse bottom
                for(int i = right - 1; i >= left; --i) {
                    spiral_order.push_back(matrix[bottom][i]);
                }
                // if left and right aren't the same column
                if(left < right) {
                    // traverse left
                    for(int i = bottom - 1; i > top; --i) {
                        spiral_order.push_back(matrix[i][left]);
                    }
                }
            }
            // shrink the boundary
            ++top; --right; --bottom; ++left;
        }
        return spiral_order;
    }
};