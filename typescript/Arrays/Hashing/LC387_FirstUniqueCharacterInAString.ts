function firstUniqChar(s: string): number {
    if(s.length === 1) return 0;
    // create hashmap to store element -> freq
    const freq = new Map<string, number>();
    for(const ch of s) {
        const frequency = freq.get(ch) ?? 0;
        freq.set(ch, frequency + 1);
    }
    for(let i = 0; i < s.length; ++i) {
        if(freq.get(s[i]) === 1) return i;
    }
    return -1;
};