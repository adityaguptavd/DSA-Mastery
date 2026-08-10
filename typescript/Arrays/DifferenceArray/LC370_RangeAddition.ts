function getModifiedArray(length: number, updates: number[][]): number[] {
    const result: number[] = Array(length).fill(0);
    const diff: number[] = Array(length + 1).fill(0);

    // build diff array
    for(const [startIndex, endIndex, inc] of updates) {
        diff[startIndex] += inc;
        diff[endIndex + 1] -= inc;
    }
    let current  = 0;
    // reconstruct result array
    for(let i = 0; i < length; ++i) {
        current += diff[i];
        result[i] = current;
    }
    return result;
}