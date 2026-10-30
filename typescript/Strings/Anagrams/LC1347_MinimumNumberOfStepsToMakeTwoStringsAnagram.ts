function minSteps(s: string, t: string): number {
    const sFreq = new Map<string, number>();
    const tFreq = new Map<string, number>();
    for(const c of t) {
        const freq = tFreq.get(c) ?? 0;
        tFreq.set(c, freq + 1);
    }
    let steps = 0;
    for(const c of s) {
        const freq = sFreq.get(c) ?? 0;
        if(freq + 1 > (tFreq.get(c) ?? 0)) {
            ++steps;
        }
        sFreq.set(c, freq + 1);
    }
    return steps;
};
