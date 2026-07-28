function intersect(nums1: number[], nums2: number[]): number[] {
    // create hashmap and result array
    const freq = new Map<number, number>();
    const intersection_result: number[] = [];
    // find the smaller sized array and build frequency hashmap from it
    let freqBuildArr = nums1;
    let findIntersectionArr = nums2;

    if(nums1.length > nums2.length) {
        freqBuildArr = nums2;
        findIntersectionArr = nums1;
    }

    // build hashmap
    for(const element of freqBuildArr) {
        freq.set(element, (freq.get(element) ?? 0) + 1);
    }

    // find intersection
    for(const element of findIntersectionArr) {
        const frequency = freq.get(element);
        if(frequency) { // should not be undefined/null/0
            freq.set(element, frequency - 1);
            intersection_result.push(element);
        }
    }
    return intersection_result;
};