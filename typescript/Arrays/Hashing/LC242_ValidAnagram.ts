// Optimized Algorithm 3
function isAnagram(s: string, t: string): boolean {
    // check for size match
    if(s.length !== t.length) {
        return false;
    }
    // create hashmap
    const freq = new Map<string, number>();
    // iterate over both strings simultaneously
    for(let i = 0; i < s.length; i++) {
        // update hashmap
        freq.set(s[i], (freq.get(s[i]) ?? 0) + 1);
        freq.set(t[i], (freq.get(t[i]) ?? 0) - 1);
    }
    // finally check if all character's frequency is zero then return true else false
    for(const [c, f] of freq) {
        if(f) return false; 
    }
    return true;
};