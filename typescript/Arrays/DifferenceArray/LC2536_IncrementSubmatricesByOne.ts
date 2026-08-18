function rangeAddQueries(n: number, queries: number[][]): number[][] {
    const diff: number[][] = Array.from({ length: n + 2 }, () => Array(n + 2).fill(0));
    const result: number[][] = Array.from({ length: n }, () => Array(n).fill(0));
    for(const [row1, col1, row2, col2] of queries) {
        ++diff[row1 + 1][col1 + 1];
        --diff[row1 + 1][col2 + 2];
        --diff[row2 + 2][col1 + 1];
        ++diff[row2 + 2][col2 + 2];
    }
    for(let row = 0; row < n; ++row) {
        for(let col = 0; col < n; ++col) {
            diff[row + 1][col + 1] += (diff[row][col + 1] + diff[row + 1][col] - diff[row][col]);
            result[row][col] = diff[row + 1][col + 1];
        }
    }
    return result;
};