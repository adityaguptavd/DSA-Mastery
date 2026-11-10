function findMedianSortedArrays(nums1: number[], nums2: number[]): number {
    let m = nums1.length;
    let n = nums2.length;
    const N = m + n;
    const leftSize = Math.ceil(N / 2);
    if(m > n) {
        [nums1, nums2, m, n] = [nums2, nums1, n, m];
    }
    let low = 0, high = m;
    while(low <= high) {
        const nums1LeftSize = Math.floor((low + high) / 2);
        const nums2LeftSize = leftSize - nums1LeftSize;
        const nums1LeftLargest = 
                        nums1LeftSize === 0 ? 
                            Number.NEGATIVE_INFINITY: 
                            nums1[nums1LeftSize - 1];
        const nums1RightSmallest = 
                        nums1LeftSize === m ? 
                            Infinity: 
                            nums1[nums1LeftSize];
        const nums2LeftLargest = 
                        nums2LeftSize === 0 ? 
                            Number.NEGATIVE_INFINITY: 
                            nums2[nums2LeftSize - 1];
        const nums2RightSmallest = 
                        nums2LeftSize === n ? 
                            Infinity: 
                            nums2[nums2LeftSize];

        if(nums1LeftLargest > nums2RightSmallest) {
            high = nums1LeftSize;
        }
        else if(nums2LeftLargest > nums1RightSmallest) {
            low = nums1LeftSize + 1;
        }
        else {
            if(N % 2 === 0) {
                return (
                    Math.max(nums1LeftLargest, nums2LeftLargest) + 
                    Math.min(nums1RightSmallest, nums2RightSmallest)
                ) / 2;
            }
            else {
                return Math.max(nums1LeftLargest, nums2LeftLargest);
            }
        }
    }
    return 0.0;
};
