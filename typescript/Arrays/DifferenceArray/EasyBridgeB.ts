function checkLimit(
    n: number,
    updates: number[][],
    limit: number
): boolean {
    const diff: number[] = Array(n + 1).fill(0);
    for(const [startIndex, endIndex, value] of updates) {
        diff[startIndex] += value;
        diff[endIndex + 1] -= value;
    }
    let current = 0;
    for(let i = 0; i < n; ++i) {
        current += diff[i];
        if(current > limit) return false;
    }
    return true;
}