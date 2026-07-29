function containsNearbyDuplicate(nums: number[], k: number): boolean {
    if(k === 0) return false;
    // create hashmap to store recent occurrence of each element
    const elemToIdxMap = new Map<number, number>();
    for(let i = 0; i < nums.length; ++i) {
        let recent_occurrence = elemToIdxMap.get(nums[i]) ?? -1;
        if(recent_occurrence !== -1) {
            if(i - recent_occurrence <= k) return true;
        }
        elemToIdxMap.set(nums[i], i);
    }
    return false;
};