function subarraysDivByK(nums: number[], k: number): number {
    let numOfSubarray = 0, prefixSum = 0;
    const remFreqMap = new Map<number, number>();
    remFreqMap.set(0, 1);
    for(const elem of nums) {
        prefixSum += elem;
        const r = (prefixSum % k + k) % k;
        const freq = remFreqMap.get(r) ?? 0;
        numOfSubarray += freq;
        remFreqMap.set(r, freq + 1);
    }
    return numOfSubarray;
};