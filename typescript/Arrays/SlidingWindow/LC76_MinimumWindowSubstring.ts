function minWindow(s: string, t: string): string {
    if(t.length > s.length) return "";
    // track minimum valid window
    let minWindowLeft = 0, // inclusive
        minWindowRight = 0; // exclusive
    // build pattern map and calculate overall required frequencies
    const patternFreq = new Map<string, number>();
    let requiredFrequencies = 0;
    for(const c of t) {
        const freq = patternFreq.get(c) ?? 0;
        if(freq == 0) ++requiredFrequencies;
        patternFreq.set(c, freq + 1);
    }
    // declare windows left boundary
    let left = 0;
    // expand window while building window frequency map and calculating matched frequencies
    const windowFreq = new Map<string, number>();
    let matchedFrequencies = 0;
    for(let right = 0; right < s.length; ++right) {
        const oldFreq = windowFreq.get(s[right]) ?? 0;
        const newFreq = oldFreq + 1;
        const reqFreq = patternFreq.get(s[right]) ?? 0;
        if(reqFreq > 0) {
            windowFreq.set(s[right], newFreq);
            if(newFreq === reqFreq) {
                ++matchedFrequencies;
            }
        }
        if(matchedFrequencies === requiredFrequencies) {
            if(minWindowRight === 0 || ((right - left + 1) < (minWindowRight - minWindowLeft))) {
                minWindowRight = right + 1;
                minWindowLeft = left;
            }
            while(left < right) {
                const oldFreq = windowFreq.get(s[left]) ?? 0;
                const newFreq = oldFreq - 1;
                const reqFreq = patternFreq.get(s[left]) ?? 0;
                if(reqFreq > 0) {
                    windowFreq.set(s[left], newFreq);
                    if(oldFreq === reqFreq) {
                        --matchedFrequencies;
                    }
                }
                ++left;
                if(matchedFrequencies === requiredFrequencies) {
                    if(minWindowRight === 0 || ((right - left + 1) < (minWindowRight - minWindowLeft))) {
                        minWindowRight = right + 1;
                        minWindowLeft = left;
                    }
                }
                else {
                    break;
                }
            }
        }
    }
    return s.substring(minWindowLeft, minWindowRight);
};
