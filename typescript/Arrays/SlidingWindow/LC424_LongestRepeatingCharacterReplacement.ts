function characterReplacement(s: string, k: number): number {
    let left: number = 0;
    let maxFreq: number = 0;
    const freqMap = new Map<string, number>();
    let maxLength: number = 0;
    for(let right = 0; right < s.length; ++right) {
        const freq = freqMap.get(s[right]) ?? 0;
        freqMap.set(s[right], freq + 1);
        maxFreq = Math.max(maxFreq, freq + 1);
        const windowSize = right - left + 1;
        if(windowSize - maxFreq > k) {
            const leavingCharFreq = freqMap.get(s[left])!;
            freqMap.set(s[left], leavingCharFreq - 1);
            ++left;
        }
        maxLength = Math.max(maxLength, right - left + 1);
    }
    return maxLength;
};