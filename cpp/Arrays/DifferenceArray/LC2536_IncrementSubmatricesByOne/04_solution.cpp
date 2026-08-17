#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> diff(n + 2, vector<int>(n + 2, 0)); // padding from all sides
        vector<vector<int>> result(n, vector<int>(n, 0));
        for(const auto& query: queries) {
            const int row1 = query[0], col1 = query[1], row2 = query[2], col2 = query[3];
            ++diff[row1 + 1][col1 + 1];
            --diff[row1 + 1][col2 + 2];
            --diff[row2 + 2][col1 + 1];
            ++diff[row2 + 2][col2 + 2];
        }
        for(int row = 0; row < n; ++row) {
            for(int col = 0; col < n; ++col) {
                diff[row + 1][col + 1] += diff[row][col + 1] + diff[row + 1][col] - diff[row][col];
                result[row][col] = diff[row + 1][col + 1];
            }
        }
        return result;
    }
};