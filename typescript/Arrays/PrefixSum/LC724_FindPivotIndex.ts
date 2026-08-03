function pivotIndex(nums: number[]): number {
    let leftSum = 0;
    let totalSum = nums.reduce((acc, curr) => acc + curr);
    for(let i = 0; i < nums.length; ++i) {
        if(leftSum == (totalSum - leftSum - nums[i])) {
            return i;
        }
        else {
            leftSum += nums[i];
        }
    }
    return -1;
};