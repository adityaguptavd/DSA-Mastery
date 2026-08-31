function findMaxAverage(nums: number[], k: number): number {
    let left = 0;
    let right = k - 1;

    let currentSum = 0;

    for (let i = 0; i <= right; ++i) {
        currentSum += nums[i];
    }

    let maxSum = currentSum;

    ++left;
    ++right;

    const numsSize = nums.length;

    while (right < numsSize) {
        currentSum = currentSum - nums[left - 1] + nums[right];

        maxSum = Math.max(maxSum, currentSum);

        ++left;
        ++right;
    }

    return maxSum / k;
}
