function maxSubArray(nums: number[]): number {
    let bestSoFar = nums[0];
    let bestEnding = nums[0];
    for(let i = 1; i < nums.length; ++i) {
        bestEnding = Math.max(bestEnding + nums[i], nums[i]);
        bestSoFar = Math.max(bestSoFar, bestEnding);
    }
    return bestSoFar;
};
