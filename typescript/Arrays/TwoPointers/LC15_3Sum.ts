function threeSum(nums: number[]): number[][] {
    const triplets: number[][] = [];
    // sort the given array
    nums.sort((a, b) => a - b);
    for(let i = 0; i <= nums.length - 3 && nums[i] <= 0;) {
        const requiredSum = -nums[i];
        // initialize pointers L and R
        let L = i + 1, R = nums.length - 1;
        while(L < R) {
            // sum of values at L and R
            const currentSum = nums[L] + nums[R];
            if(currentSum < requiredSum) ++L;
            else if(currentSum > requiredSum) --R;
            else {
                // store the triplets
                triplets.push([nums[i], nums[L], nums[R]]);
                // increment L and R skipping duplicates
                do{
                    ++L;
                } while(L < R && nums[L] == nums[L - 1]);

                do{
                    --R;
                } while(L < R && nums[R] == nums[R + 1]);
            }
        }
        // increment i avoiding duplicates
        do{
            ++i;
        } while(i <= nums.length - 3 && nums[i] == nums[i - 1]);
    }
    return triplets;
};