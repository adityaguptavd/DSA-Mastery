function subarraySum(nums: number[], k: number): number {
    let prefixSum = 0;
    let num_of_subarrays = 0;
    const prefixSumFreqMap = new Map<number, number>();
    for(const elem of nums) {
        prefixSum += elem;
        if(prefixSum === k) {
            ++num_of_subarrays;
        }
        const requiredPrefixSum = prefixSum - k;
        if(prefixSumFreqMap.has(requiredPrefixSum)) {
            num_of_subarrays += prefixSumFreqMap.get(requiredPrefixSum)!;
        }
        prefixSumFreqMap.set(prefixSum, (prefixSumFreqMap.get(prefixSum) ?? 0) + 1);
    }
    return num_of_subarrays;
};