function frequencySort(s: string): string {
    const freqMap = new Map<string, number>();
    let distinctChars = "";
    for(const c of s) {
        const freq = freqMap.get(c) ?? 0;
        if(freq == 0) {
            distinctChars += c;
        }
        freqMap.set(c, freq + 1);
    }
    let result = "";
    const sortedDistinctChars = distinctChars.split("").sort((a, b) => freqMap.get(b)! - freqMap.get(a)!);
    for(const c of sortedDistinctChars) {
        result += c.repeat(freqMap.get(c)!);
    }
    return result;
};
