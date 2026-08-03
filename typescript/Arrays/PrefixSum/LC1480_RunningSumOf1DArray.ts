function runningSum(nums: number[]): number[] {
    const output: number[] = [];
    output[0] = nums[0];
    for(let i = 0; i < nums.length; ++i) {
        output[i] = output[i - 1] + nums[i];
    }
    return output;
};