function findMaxLength(nums: number[]): number {
    const prefixSumFirstOccurrence = new Map<number, number>();
    prefixSumFirstOccurrence.set(0, -1);
    let runningPrefixSum = 0;
    let length_of_max_subarray = 0;
    for (let i = 0; i < nums.length; ++i) {
        runningPrefixSum += (nums[i] === 0) ? -1: 1;
        const firstOccurrence = prefixSumFirstOccurrence.get(runningPrefixSum);
        if(firstOccurrence !== undefined) {
            length_of_max_subarray = Math.max(length_of_max_subarray, i - firstOccurrence);
        }
        else {
            prefixSumFirstOccurrence.set(runningPrefixSum, i);
        }
    }
    return length_of_max_subarray;
};