function minSubArrayLen(target: number, nums: number[]): number {
    let left = 0;
    let currentSum = 0;
    let minSize = Infinity;

    for (let right = 0; right < nums.length; right++) {
        currentSum += nums[right];

        while (currentSum >= target) {
            minSize = Math.min(minSize, right - left + 1);
            currentSum -= nums[left];
            left++;
        }
    }

    return minSize === Infinity ? 0 : minSize;
}
