function lengthOfLongestSubstring(s: string): number {
    let maximumLength = 0;
    // sliding window's boundary
    let left = 0, right = 0;
    // window state
    const seen = new Map<string, number>();
    // extend right and calculate first valid window
    while(right < s.length) {
        const seenAt = seen.get(s[right]);
        // if already seen at some index
        if(seenAt !== undefined && left <= seenAt) {
            // move left afterwards
            left = seenAt + 1;
        }
        // update maximum
        maximumLength = Math.max(maximumLength, right - left + 1);
        // update seen index
        seen.set(s[right], right);
        // expand window
        ++right;
    }
    return maximumLength;
};
