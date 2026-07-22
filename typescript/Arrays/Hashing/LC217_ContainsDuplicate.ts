function containsDuplicate(nums: number[]): boolean {
    if(nums.length <= 1) return false;
    const seen = new Set<number>();
    for(const x of nums) {
        if(seen.has(x)) return true;
        seen.add(x);
    }
    return false;
};