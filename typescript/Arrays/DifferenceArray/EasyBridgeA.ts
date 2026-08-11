function getUpdatedArray(nums: number[], updates: number[][]): void {
    const diff: number[] = Array(nums.length + 1).fill(0);

    // build diff array
    for(const [startIndex, endIndex, inc] of updates) {
        diff[startIndex] += inc;
        diff[endIndex + 1] -= inc;
    }
    let current  = 0;
    // reconstruct result array
    for(let i = 0; i < nums.length; ++i) {
        current += diff[i];
        nums[i] += current;
    }
}