function searchLowerIndex(nums: number[], target: number): number {
    let left = 0, right = nums.length - 1;
    let lowerIndex = -1;
    while(left <= right) {
        let mid = Math.floor(left + (right - left) / 2);
        if(nums[mid] < target) {
            left = mid + 1;
        }
        else if(nums[mid] > target) {
            right = mid - 1;
        }
        else {
            lowerIndex = mid;
            right = mid - 1;
        }
    }
    return lowerIndex;
}

function searchUpperIndex(nums: number[], target: number): number {
    let left = 0, right = nums.length - 1;
    let upperIndex = -1;
    while(left <= right) {
        let mid = Math.floor(left + (right - left) / 2);
        if(nums[mid] < target) {
            left = mid + 1;
        }
        else if(nums[mid] > target) {
            right = mid - 1;
        }
        else {
            upperIndex = mid;
            left = mid + 1;
        }
    }
    return upperIndex;
}

function searchRange(nums: number[], target: number): number[] {
    return [
        searchLowerIndex(nums, target),
        searchUpperIndex(nums, target)
    ];
};
