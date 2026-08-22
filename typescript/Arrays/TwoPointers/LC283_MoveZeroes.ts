/**
 Do not return anything, modify nums in-place instead.
 */

function moveZeroes(nums: number[]): void {
    let nums_size = nums.length;
    // create read/write pointers
    let read = 0, write = 0;
    while(read < nums_size && write < nums_size) {
        // find the position where first non-zero value will go
        if(nums[write] != 0) {
            ++write;
            continue;
        }
        // find first non-zero value onwards
        read = write + 1;
        while(read < nums_size) {
            if(nums[read] == 0) {
                ++read;
                continue;
            }
            // swap the zero and non-zero value
            nums[write] = nums[read];
            nums[read] = 0;
            ++read; ++write;
            break;
        }
    }
};