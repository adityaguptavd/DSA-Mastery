function longestOnes(nums: number[], k: number): number {
    // initialize left and right boundary of the window
    let left = 0;
    let right = 0;

    // counter for zeroes encountered in the window
    let zeroCount = 0;

    // array size
    const n = nums.length;

    while (right < n) {
        if (nums[right] === 0) {
            ++zeroCount;
        }

        // if window is invalid, shrink lazily
        if (zeroCount > k) {
            ++left;

            // if the leaving element is zero
            if (nums[left - 1] === 0) {
                --zeroCount;
            }
        }

        // expand the window
        ++right;
    }

    // return size of maximum valid window
    return right - left;
}
